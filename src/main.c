/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apregitz <apregitz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/02 21:00:05 by anakin            #+#    #+#             */
/*   Updated: 2025/04/20 11:44:34 by apregitz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

// int	is_valid(t_cords cords, t_zoom zoom)
// {
// 	if ((cords.x > zoom.view_x ))
// }

void	print_fractol(t_data *data)
{
	t_cords		cords;
	t_complx	c;
	t_complx	z;

	z.imag = 0;
	z.real = 0;
	cords.y = 0;
	while (cords.y < HEIGHT)
	{
		cords.x = 0;
		while (cords.x < WIDTH)
		{
			c = calc_zoomed_pix(&data->zoom, cords);
			clac_pixel(z, c, cords, data);
			cords.x++;
		}
		cords.y++;
	}
}

int	main(int ac, char **av)
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
	// mlx_key_hook(data.mlx, key_move_hook, &data);
	// mlx_loop_hook(data.mlx, &key_zoom_hook, &data);
	// mlx_loop_hook(data.mlx, &key_move_hook, &data);
	print_fractol(&data);
	mlx_loop(data.mlx);
	mlx_terminate(data.mlx);
	return (0);
}
