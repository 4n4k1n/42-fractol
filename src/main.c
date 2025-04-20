/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apregitz <apregitz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/02 21:00:05 by anakin            #+#    #+#             */
/*   Updated: 2025/04/20 17:22:16 by apregitz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

void	print_fractol(t_data *data)
{
	t_cords		cords;
	t_complx	c;
	t_complx	z;

	z.imag = 0;
	z.real = 0;
	cords.y = 0;
	while (cords.y < data->zoom.win_height)
	{
		cords.x = 0;
		while (cords.x < data->zoom.win_width)
		{
			data->func_ptr(data, cords, &z, &c);
			cords.x++;
		}
		cords.y++;
	}
}

int	main(int ac, char **av)
{
	t_data	data;

	if (!check_arguments(ac, av, &data))
		return (1);
	mlx_set_setting(MLX_MAXIMIZED, false);
	data.mlx = mlx_init(WIDTH, HEIGHT, "Fractol", true);
	if (!data.mlx)
		return (1);
	data.img = mlx_new_image(data.mlx, WIDTH, HEIGHT);
	if (!data.img || (mlx_image_to_window(data.mlx, data.img, 0, 0) < 0))
		return (free(data.mlx), free(data.img), 1);
	mlx_resize_hook(data.mlx, resize_window, &data);
	init_zoom(&data.zoom);
	mlx_key_hook(data.mlx, key_zoom_hook, &data);
	print_fractol(&data);
	mlx_loop(data.mlx);
	mlx_terminate(data.mlx);
	return (0);
}
