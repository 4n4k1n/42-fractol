/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   resize_hook.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apregitz <apregitz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/20 17:16:55 by apregitz          #+#    #+#             */
/*   Updated: 2025/04/20 17:21:44 by apregitz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

void resize_window(int32_t width, int32_t height, void *param)
{
	t_data *data;

	data = param;
	data->zoom.win_height = height;
	data->zoom.win_width = width;
	mlx_delete_image(data->mlx, data->img);
	data->img = mlx_new_image(data->mlx, width, height);
	if (!data->img)
		mlx_close_window(data->mlx);
	if (mlx_image_to_window(data->mlx, data->img, 0, 0) < 0)
		mlx_close_window(data->mlx);
	print_fractol(data);
}
