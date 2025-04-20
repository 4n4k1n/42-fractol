/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_zoom_hook.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apregitz <apregitz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/13 16:39:51 by apregitz          #+#    #+#             */
/*   Updated: 2025/04/20 17:18:27 by apregitz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

void	key_zoom_hook(mlx_key_data_t keys, void *param)
{
	t_data	*data;
	t_cords	middle;

	data = param;
	middle.x = data->zoom.win_width / 2;
	middle.y = data->zoom.win_height / 2;
	if (keys.action == MLX_PRESS)
	{
		if (keys.key == MLX_KEY_ESCAPE)
			mlx_close_window(data->mlx);
		else if (keys.key == MLX_KEY_EQUAL || keys.key == MLX_KEY_MINUS)
		{
			if (keys.key == MLX_KEY_EQUAL)
				zoom_in(&middle, &data->zoom);
			else
				zoom_out(&middle, &data->zoom);
			mlx_delete_image(data->mlx, data->img);
			data->img = mlx_new_image(data->mlx, data->zoom.win_width, data->zoom.win_height);
			mlx_image_to_window(data->mlx, data->img, 0, 0);
			print_fractol(data);
		}
		if (keys.key == MLX_KEY_W || keys.key == MLX_KEY_S || keys.key == MLX_KEY_A || keys.key == MLX_KEY_D)
		{
			if (keys.key == MLX_KEY_W)
				data->zoom.view_y -= 15 * data->zoom.scale;
			else if (keys.key == MLX_KEY_S)
				data->zoom.view_y += 15 * data->zoom.scale;
			else if (keys.key == MLX_KEY_D)
				data->zoom.view_x += 15 * data->zoom.scale;
			else
				data->zoom.view_x -= 15 * data->zoom.scale;
			mlx_delete_image(data->mlx, data->img);
			data->img = mlx_new_image(data->mlx, data->zoom.win_width, data->zoom.win_height);
			mlx_image_to_window(data->mlx, data->img, 0, 0);
			print_fractol(data);
		}
	}
}
