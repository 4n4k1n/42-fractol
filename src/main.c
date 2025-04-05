/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anakin <anakin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/02 21:00:05 by anakin            #+#    #+#             */
/*   Updated: 2025/04/05 06:03:45 by anakin           ###   ########.fr       */
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
		mlx_put_pixel(img, cords.x, cords.y, 0xffffffff);
}

void    print_fractol(mlx_image_t *img)
{
    t_cords     cords;
    t_maped     map;
    t_complx    c;
    t_complx    z;

    init_mandelbrot_structs(&map, &z);
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
        write(1, "\n", 1);
        cords.y++;
    }
}

int32_t main(void)
{
    mlx_set_setting(MLX_MAXIMIZED, true);
    mlx_t* mlx = mlx_init(WIDTH, HEIGHT, "42Balls", false);
    if (!mlx)
        return (1);
    mlx_image_t* img = mlx_new_image(mlx, WIDTH, HEIGHT);
    if (!img || (mlx_image_to_window(mlx, img, 0, 0) < 0))
        return (free(mlx), free(img), 1);
    print_fractol(img);
    mlx_loop(mlx);
    mlx_terminate(mlx);
    return (EXIT_SUCCESS);
}