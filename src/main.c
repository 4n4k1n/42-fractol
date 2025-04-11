/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apregitz <apregitz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/02 21:00:05 by anakin            #+#    #+#             */
/*   Updated: 2025/04/11 22:47:14 by apregitz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

t_complx	calculate_c(t_maped map, t_cords cords)
{
	t_complx complx;

	complx.real = map.min_x + (map.max_x - map.min_x) * cords.x / (WIDTH - 1);
	complx.imag = map.min_y + (map.max_y - map.min_y) * cords.y / (HEIGHT - 1);
	return (complx);
}

void	calc_zoomed_pix(t_zoom *zoom, t_cords *cords, t_cords *new_cords)
{
	new_cords->x = (cords->x - (zoom->win_width / 2)) * zoom->scale + zoom->view_x;
	new_cords->y = (cords->y - (zoom->win_height / 2)) * zoom->scale + zoom->view_y; 
}

void	calculate_zoomed_map(t_zoom *zoom, t_maped *map)
{
	t_cords top_left = {0, 0};
	t_cords bottom_right = {WIDTH - 1, HEIGHT - 1};
	t_cords zoomed_top_left;
	t_cords zoomed_bottom_right;
	
	// Calculate normalized coordinates for corners
	calc_zoomed_pix(zoom, &top_left, &zoomed_top_left);
	calc_zoomed_pix(zoom, &bottom_right, &zoomed_bottom_right);
	
	// Map to the fractal coordinate space (using the original map range)
	t_maped original_map = {-2, 2, -2, 2}; // Default Mandelbrot bounds
	
	map->min_x = original_map.min_x + (original_map.max_x - original_map.min_x) * zoomed_top_left.x / (WIDTH - 1);
	map->max_x = original_map.min_x + (original_map.max_x - original_map.min_x) * zoomed_bottom_right.x / (WIDTH - 1);
	map->min_y = original_map.min_y + (original_map.max_y - original_map.min_y) * zoomed_top_left.y / (HEIGHT - 1);
	map->max_y = original_map.min_y + (original_map.max_y - original_map.min_y) * zoomed_bottom_right.y / (HEIGHT - 1);
}

void	init_zoom(t_zoom *zoom)
{
	zoom->scale = 1.0;           // Start with no zoom
	zoom->view_x = 0.0;          // Center view initially
	zoom->view_y = 0.0;          // Center view initially
	zoom->win_width = WIDTH;
	zoom->win_height = HEIGHT;
	zoom->mouse_pressed = 0;     // Mouse not pressed initially
}

void	zoom_in(t_cords *mouse, t_zoom *zoom, t_cords *pixel)
{
	t_cords	before;
	t_cords	after;
	
	calc_zoomed_pix(zoom, mouse, &before);
	zoom->scale *= 0.95;
	calc_zoomed_pix(zoom, mouse, &after);
	zoom->view_x += (before.x - after.x);
	zoom->view_y += (before.y - after.y); 
}

void	zoom_out(t_cords *mouse, t_zoom *zoom, t_cords *pixel)
{
	t_cords	before;
	t_cords	after;
	
	calc_zoomed_pix(zoom, mouse, &before);
	zoom->scale *= 1.05;
	calc_zoomed_pix(zoom, mouse, &after);
	zoom->view_x += (before.x - after.x);
	zoom->view_y += (before.y - after.y);
}

void	pan(t_zoom *zoom, int dx, int dy)
{
	// Adjust viewpoint based on mouse movement
	zoom->view_x -= dx * zoom->scale;
	zoom->view_y -= dy * zoom->scale;
}

t_complx	calc_next_iter_num(t_complx z, t_complx c)
{
	t_complx	new_z;

	new_z.real = pow(z.real, 2) - pow(z.imag, 2) + c.real;
	new_z.imag = z.real * z.imag + c.imag;
	return (new_z);
}

void	init_mandelbrot_structs(t_maped *map, t_complx *complxx_num)
{
	map->min_x = -2;
	map->max_x = 2;
	map->min_y = -2;
	map->max_y = 2;
	complxx_num->imag = 0;
	complxx_num->real = 0;
}

void	clac_pixel(t_complx z, t_complx c, t_cords cords, mlx_image_t *img)
{
	int i;
	t_complx	temp;
	
	i = 0;
	while (pow(z.real, 2) + pow(z.imag, 2) < 4 && i < MAX_ITER)
	{
		temp.real = pow(z.real, 2) - pow(z.imag, 2) + c.real;
		temp.imag = 2 * z.real * z.imag + c.imag;
		z.real = temp.real;
		z.imag = temp.imag;
		i++;
	}
	if (i == MAX_ITER)
		mlx_put_pixel(img, cords.x, cords.y, 0x000000ff);
	else
	{
		// Color smoothing for better visualization
		int color = 0xffffff - ((i * 0xffffff) / MAX_ITER);
		mlx_put_pixel(img, cords.x, cords.y, color | 0xff);
	}
}

void    print_fractol(mlx_image_t *img, t_zoom *zoom)
{
    t_cords     cords;
    t_maped     map;
    t_complx    c;
    t_complx    z;

    init_mandelbrot_structs(&map, &z);
    
    // Apply zoom transformation to the map
    if (zoom->scale != 1.0 || zoom->view_x != 0.0 || zoom->view_y != 0.0)
        calculate_zoomed_map(zoom, &map);
    
    cords.y = 0;
    while (cords.y < HEIGHT)
    {
        cords.x = 0;
        while (cords.x < WIDTH)
        {
            c = calculate_c(map, cords);
            clac_pixel(z, c, cords, img);
            cords.x++;
        }
        cords.y++;
    }
}

void key_hook(mlx_key_data_t keydata, void *param)
{
    t_fractal_data *data = param;
    
    if (keydata.key == MLX_KEY_ESCAPE && keydata.action == MLX_PRESS)
        mlx_close_window(data->mlx);
    else if (keydata.key == MLX_KEY_EQUAL && keydata.action == MLX_PRESS)
    {
        // Zoom in at center
        t_cords center = {WIDTH / 2, HEIGHT / 2};
        zoom_in(&center, &data->zoom, &center);
        mlx_delete_image(data->mlx, data->img);
        data->img = mlx_new_image(data->mlx, WIDTH, HEIGHT);
        mlx_image_to_window(data->mlx, data->img, 0, 0);
        print_fractol(data->img, &data->zoom);
    }
    else if (keydata.key == MLX_KEY_MINUS && keydata.action == MLX_PRESS)
    {
        // Zoom out at center
        t_cords center = {WIDTH / 2, HEIGHT / 2};
        zoom_out(&center, &data->zoom, &center);
        mlx_delete_image(data->mlx, data->img);
        data->img = mlx_new_image(data->mlx, WIDTH, HEIGHT);
        mlx_image_to_window(data->mlx, data->img, 0, 0);
        print_fractol(data->img, &data->zoom);
    }
}

void scroll_hook(double xdelta, double ydelta, void *param)
{
    t_fractal_data *data = param;
    t_cords mouse;
    int32_t pos[2];
    
    // Get current mouse position
    mlx_get_mouse_pos(data->mlx, &pos[0], &pos[1]);
    mouse.x = pos[0];
    mouse.y = pos[1];
    
    if (ydelta > 0)
        zoom_in(&mouse, &data->zoom, &mouse);
    else if (ydelta < 0)
        zoom_out(&mouse, &data->zoom, &mouse);
    
    // Redraw the fractal
    mlx_delete_image(data->mlx, data->img);
    data->img = mlx_new_image(data->mlx, WIDTH, HEIGHT);
    mlx_image_to_window(data->mlx, data->img, 0, 0);
    print_fractol(data->img, &data->zoom);
}

void mouse_hook(mouse_key_t button, action_t action, modifier_key_t mods, void *param)
{
    t_fractal_data *data = param;
    
    if (button == MLX_MOUSE_BUTTON_LEFT)
    {
        if (action == MLX_PRESS)
            data->zoom.mouse_pressed = 1;
        else if (action == MLX_RELEASE)
            data->zoom.mouse_pressed = 0;
    }
}

void cursor_hook(double xpos, double ypos, void *param)
{
    t_fractal_data *data = param;
    static double last_x = 0;
    static double last_y = 0;
    static int is_first = 1;
    
    if (is_first)
    {
        last_x = xpos;
        last_y = ypos;
        is_first = 0;
        return;
    }
    
    if (data->zoom.mouse_pressed)
    {
        // Calculate movement delta
        double dx = xpos - last_x;
        double dy = ypos - last_y;
        
        // Pan the view
        pan(&data->zoom, dx, dy);
        
        // Redraw
        mlx_delete_image(data->mlx, data->img);
        data->img = mlx_new_image(data->mlx, WIDTH, HEIGHT);
        mlx_image_to_window(data->mlx, data->img, 0, 0);
        print_fractol(data->img, &data->zoom);
    }
    
    // Update last position
    last_x = xpos;
    last_y = ypos;
}

int32_t main(void)
{
    t_fractal_data data;
    
    mlx_set_setting(MLX_MAXIMIZED, true);
    data.mlx = mlx_init(WIDTH, HEIGHT, "42 Fractal", false);
    if (!data.mlx)
        return (1);
    
    data.img = mlx_new_image(data.mlx, WIDTH, HEIGHT);
    if (!data.img || (mlx_image_to_window(data.mlx, data.img, 0, 0) < 0))
        return (free(data.mlx), free(data.img), 1);
    
    // Initialize zoom
    init_zoom(&data.zoom);
    
    // Set up hooks
    mlx_key_hook(data.mlx, key_hook, &data);
    mlx_scroll_hook(data.mlx, scroll_hook, &data);
    mlx_mouse_hook(data.mlx, mouse_hook, &data);
    mlx_cursor_hook(data.mlx, cursor_hook, &data);
    
    // Draw initial fractal
    print_fractol(data.img, &data.zoom);
    
    mlx_loop(data.mlx);
    mlx_terminate(data.mlx);
    return (EXIT_SUCCESS);
}
