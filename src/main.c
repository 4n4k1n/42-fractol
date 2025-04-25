/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apregitz <apregitz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/02 21:00:05 by anakin            #+#    #+#             */
/*   Updated: 2025/04/26 00:21:20 by apregitz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

int	main(int ac, char **av)
{
	t_data	data;

	if (!check_arguments(ac, av, &data))
		return (1);
	init_rgb(&data.rgb);
	mlx_set_setting(MLX_MAXIMIZED, false);
	data.mlx = mlx_init(WIDTH, HEIGHT, "Fractol", true);
	if (!data.mlx)
		return (1);
	data.img = mlx_new_image(data.mlx, WIDTH, HEIGHT);
	if (!data.img || (mlx_image_to_window(data.mlx, data.img, 0, 0) < 0))
		return (free(data.mlx), free(data.img), 1);
	mlx_resize_hook(data.mlx, resize_window_hook, &data);
	init_zoom(&data.zoom);
	mlx_key_hook(data.mlx, key_hook, &data);
	mlx_scroll_hook(data.mlx, &scroll_hook, &data);
	print_fractol(&data);
	mlx_loop(data.mlx);
	mlx_terminate(data.mlx);
	return (0);
}
