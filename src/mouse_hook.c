/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_hook.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apregitz <apregitz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/24 21:41:49 by apregitz          #+#    #+#             */
/*   Updated: 2025/04/25 21:09:32 by apregitz         ###   ########.fr       */
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
	mlx_delete_image(data->mlx, data->img);
	data->img = mlx_new_image(data->mlx, data->zoom.win_width, data->zoom.win_height);
	mlx_image_to_window(data->mlx, data->img, 0, 0);
	print_fractol(data);
}


void	mouse_hook(mouse_key_t button, action_t action, modifier_key_t mods, void *param)
{
	t_data	*data;
	t_cords	mouse;

	data = param;
	mlx_get_mouse_pos(data->mlx, &(mouse.x), &(mouse.y));
	(void)mods;
	if (action == MLX_PRESS)
	{
		if (button == MLX_MOUSE_BUTTON_LEFT)
			data->zoom.mouse_status = 1;
		else if (button == MLX_MOUSE_BUTTON_RIGHT)
		{
			init_zoom(&data->zoom);
			mlx_delete_image(data->mlx, data->img);
			data->img = mlx_new_image(data->mlx, data->zoom.win_width, data->zoom.win_height);
			mlx_image_to_window(data->mlx, data->img, 0, 0);
			print_fractol(data);
		}
	}
	else if (action == MLX_RELEASE && button == MLX_MOUSE_BUTTON_LEFT)
		data->zoom.mouse_status = 0;
} 
