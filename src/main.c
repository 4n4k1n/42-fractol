/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apregitz <apregitz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/02 21:00:05 by anakin            #+#    #+#             */
/*   Updated: 2025/04/14 10:55:34 by apregitz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

void	print_fractol(mlx_image_t *img, t_zoom *zoom)
{
	t_cords		cords;
	t_maped		map;
	t_complx	c;
	t_complx	z;

	init_mandelbrot_structs(&map, &z);
	// if (zoom->scale != 1.0 || zoom->view_x != 0.0 || zoom->view_y != 0.0)
	// 	calculate_zoomed_map(zoom, &map);
	cords.y = 0;
	while (cords.y < HEIGHT)
	{
		cords.x = 0;
		while (cords.x < WIDTH)
		{
			c = calc_zoomed_pix(zoom, cords);
			clac_pixel(z, c, cords, img);
			cords.x++;
		}
		cords.y++;
	}
}

int	main(void)
{
	t_data	data;

	mlx_set_setting(MLX_MAXIMIZED, true);
	data.mlx = mlx_init(WIDTH, HEIGHT, "Fractal", false);
	if (!data.mlx)
		return (1);
	data.img = mlx_new_image(data.mlx, WIDTH, HEIGHT);
	if (!data.img || (mlx_image_to_window(data.mlx, data.img, 0, 0) < 0))
		return (free(data.mlx), free(data.img), 1);
	init_zoom(&data.zoom);
	mlx_key_hook(data.mlx, key_zoom_hook, &data);
	print_fractol(data.img, &data.zoom);
	mlx_loop(data.mlx);
	mlx_terminate(data.mlx);
	return (0);
}
