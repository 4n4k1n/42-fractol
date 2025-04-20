/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hook.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apregitz <apregitz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/13 16:39:51 by apregitz          #+#    #+#             */
/*   Updated: 2025/04/13 17:14:50 by apregitz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../fractol.h"

void	key_zoom_hook(mlx_key_data_t key, void *param)
{
	t_data	*data;
	t_cords	middle;

	data = param;
	middle.x = WIDTH / 2;
	middle.y = HEIGHT / 2;
	if (key.key == MLX_KEY_ESCAPE && key.action == MLX_PRESS)
		mlx_close_window(data->mlx);
	else if (key.key == MLX_KEY_EQUAL && key.action == MLX_PRESS)
	{
		zoom_in(&middle, &data->zoom, &middle);
		mlx_delete_image(data->mlx, data->img);
		data->img = mlx_new_image(data->mlx, WIDTH, HEIGHT);
		mlx_image_to_window(data->mlx, data->img, 0, 0);
		print_fractol(data->img, &data->zoom);
	}
	else if (key.key == MLX_KEY_MINUS && key.action == MLX_PRESS)
	{
		zoom_out(&middle, &data->zoom, &middle);
		data->img = mlx_new_image(data->mlx, WIDTH, HEIGHT);
		mlx_image_to_window(data->mlx, data->img, 0, 0);
		print_fractol(data->img, &data->zoom);
	}
}
