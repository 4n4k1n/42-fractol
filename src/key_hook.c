/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hook.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apregitz <apregitz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/13 16:39:51 by apregitz          #+#    #+#             */
/*   Updated: 2025/04/26 14:59:18 by apregitz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

static void	change_fractol_keys(mlx_key_data_t keys, t_data *data)
{
	if (keys.key == MLX_KEY_N)
		change_fractol(data);
}

static void	zoom_keys(mlx_key_data_t keys, t_data *data, t_cords middle)
{
	if (keys.key == MLX_KEY_EQUAL)
		zoom_in(&middle, &data->zoom);
	else if (keys.key == MLX_KEY_MINUS)
		zoom_out(&middle, &data->zoom);
}

static void	move_keys(mlx_key_data_t keys, t_data *data)
{
	if (keys.key == MLX_KEY_UP || keys.key == MLX_KEY_W)
		data->zoom.view_y -= 15 * data->zoom.scale;
	else if (keys.key == MLX_KEY_DOWN || keys.key == MLX_KEY_S)
		data->zoom.view_y += 15 * data->zoom.scale;
	else if (keys.key == MLX_KEY_RIGHT || keys.key == MLX_KEY_D)
		data->zoom.view_x += 15 * data->zoom.scale;
	else if (keys.key == MLX_KEY_LEFT || keys.key == MLX_KEY_A)
		data->zoom.view_x -= 15 * data->zoom.scale;
}

static void	color_keys(mlx_key_data_t keys, t_data *data)
{
	if (keys.key == MLX_KEY_P)
		color_flow(data);
}

void	key_hook(mlx_key_data_t keys, void *param)
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
		change_fractol_keys(keys, data);
		if (keys.key == MLX_KEY_R)
			data->rgb.rainbow *= -1;
		if (!recreate_img(data))
			return ;
		print_fractol(data);
	}
}
