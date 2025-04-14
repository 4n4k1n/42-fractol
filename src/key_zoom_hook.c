/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hook.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apregitz <apregitz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/13 16:39:51 by apregitz          #+#    #+#             */
/*   Updated: 2025/04/14 10:40:16 by apregitz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

void	key_zoom_hook(mlx_key_data_t keys, void *param)
{
	t_data	*data;
	t_cords	middle;

	data = param;
	middle.x = WIDTH / 2;
	middle.y = HEIGHT / 2;
	if (keys.key == MLX_KEY_ESCAPE && keys.action == MLX_PRESS)
		mlx_close_window(data->mlx);
	else if ((keys.key == MLX_KEY_EQUAL || keys.key == MLX_KEY_MINUS) \
	&& keys.action == MLX_PRESS)
	{
		if (keys.key == MLX_KEY_EQUAL)
			zoom_in(&middle, &data->zoom);
		else
			zoom_out(&middle, &data->zoom);
		mlx_delete_image(data->mlx, data->img);
		data->img = mlx_new_image(data->mlx, WIDTH, HEIGHT);
		mlx_image_to_window(data->mlx, data->img, 0, 0);
		print_fractol(data->img, &data->zoom);
	}
}
