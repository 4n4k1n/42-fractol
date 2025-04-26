/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   recreate_img.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apregitz <apregitz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/26 14:16:39 by apregitz          #+#    #+#             */
/*   Updated: 2025/04/26 14:20:54 by apregitz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

int	recreate_img(t_data *data)
{
	mlx_delete_image(data->mlx, data->img);
	data->img = mlx_new_image(data->mlx, data->zoom.win_width, \
		data->zoom.win_height);
	if (!data->img || mlx_image_to_window(data->mlx, data->img, 0, 0) < 0)
		return (mlx_close_window(data->mlx), 0);
	return (1);
}
