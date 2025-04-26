/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_hook.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apregitz <apregitz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/24 21:41:49 by apregitz          #+#    #+#             */
/*   Updated: 2025/04/26 14:49:30 by apregitz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

void	scroll_hook(double x_state, double y_state, void *param)
{
	t_data	*data;
	t_cords	mouse;

	data = param;
	mlx_get_mouse_pos(data->mlx, &(mouse.x), &(mouse.y));
	(void)x_state;
	if (y_state > 0)
		zoom_in(&mouse, &data->zoom);
	else if (y_state < 0)
		zoom_out(&mouse, &data->zoom);
	if (!recreate_img(data))
		return ;
	print_fractol(data);
}
