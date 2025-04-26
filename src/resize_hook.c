/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   resize_hook.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apregitz <apregitz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/20 17:16:55 by apregitz          #+#    #+#             */
/*   Updated: 2025/04/26 14:31:01 by apregitz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

void	resize_window_hook(int32_t width, int32_t height, void *param)
{
	t_data	*data;

	data = param;
	data->zoom.win_height = height;
	data->zoom.win_width = width;
	if (!recreate_img(data))
		return (mlx_terminate(data->mlx));
	print_fractol(data);
}
