/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_zoom_hook.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apregitz <apregitz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/13 16:39:51 by apregitz          #+#    #+#             */
/*   Updated: 2025/04/23 14:04:03 by apregitz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

static void	zoom_keys(mlx_key_data_t keys, t_data *data, t_cords middle)
{
	if (keys.key == MLX_KEY_EQUAL)
		zoom_in(&middle, &data->zoom);
	else if (keys.key == MLX_KEY_MINUS)
		zoom_out(&middle, &data->zoom);
}

static void	move_keys(mlx_key_data_t keys, t_data *data)
{
	if (keys.key == MLX_KEY_UP)
		data->zoom.view_y -= 15 * data->zoom.scale;
	else if (keys.key == MLX_KEY_DOWN)
		data->zoom.view_y += 15 * data->zoom.scale;
	else if (keys.key == MLX_KEY_RIGHT)
		data->zoom.view_x += 15 * data->zoom.scale;
	else if (keys.key == MLX_KEY_LEFT)
		data->zoom.view_x -= 15 * data->zoom.scale;
}

void	increase_color_part(t_color_byte *byte)
{
	if (byte->state)
	{
		byte->color += 0.05;
		if (byte->color + 0.05 > 1.0)
			byte->state = 0;
	}
	else
	{
		byte->color -= 0.05;
		if (byte->color - 0.05 < 0.0)
			byte->state = 1;
	}
}

void	color_flow(t_data *data)
{
	increase_color_part(&(data->rgb.r));
	increase_color_part(&(data->rgb.g));
	increase_color_part(&(data->rgb.b));
}

static void	color_keys(mlx_key_data_t keys, t_data *data)
{
	if (keys.key == MLX_KEY_P)
		color_flow(data);
}

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
			return (mlx_close_window(data->mlx));
		zoom_keys(keys, data, middle);
		move_keys(keys, data);
		color_keys(keys, data);
		if (keys.key == MLX_KEY_R)
			data->rgb.rainbow *= -1;
		mlx_delete_image(data->mlx, data->img);
		data->img = mlx_new_image(data->mlx, data->zoom.win_width, data->zoom.win_height);
		mlx_image_to_window(data->mlx, data->img, 0, 0);
		print_fractol(data);
	}
}
