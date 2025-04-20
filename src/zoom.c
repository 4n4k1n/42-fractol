/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zoom.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apregitz <apregitz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/13 20:08:54 by apregitz          #+#    #+#             */
/*   Updated: 2025/04/16 12:15:29 by apregitz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

t_complx	calc_zoomed_pix(t_zoom *zoom, t_cords cords)
{
	t_complx	new_cords;

	new_cords.real = (cords.x - (zoom->win_width / 2)) \
	* zoom->scale + zoom->view_x;
	new_cords.imag = (cords.y - (zoom->win_height / 2)) \
	* zoom->scale + zoom->view_y;
	return (new_cords);
}

// void	calculate_zoomed_map(t_zoom *zoom, t_maped *map)
// {
// 	t_complx	top_left;
// 	t_complx	bottom_right;

// 	top_left.real = 0;
// 	top_left.imag = 0;
// 	bottom_right.real = WIDTH - 1;
// 	bottom_right.imag = HEIGHT - 1;
// 	top_left = calc_zoomed_pix(zoom, top_left);
// 	bottom_right = calc_zoomed_pix(zoom, bottom_right);
// 	map->min_x = org.min_x + (org.max_x - org.min_x) \
// 	* top_left.real / (WIDTH - 1);
// 	map->max_x = org.min_x + (org.max_x - org.min_x) \
// 	* bottom_right.real / (WIDTH - 1);
// 	map->min_y = org.min_y + (org.max_y - org.min_y) \
// 	* top_left.imag / (HEIGHT - 1);
// 	map->max_y = org.min_y + (org.max_y - org.min_y) \
// 	* bottom_right.imag / (HEIGHT - 1);
// }

void	init_zoom(t_zoom *zoom)
{
	zoom->scale = 0.01;
	zoom->view_x = 0.0;
	zoom->view_y = 0.0;
	zoom->win_width = WIDTH;
	zoom->win_height = HEIGHT;
	zoom->mouse_status = 0;
}

void	zoom_in(t_cords *mouse, t_zoom *zoom)
{
	t_complx	temp;
	t_complx	new;

	temp = calc_zoomed_pix(zoom, *mouse);
	zoom->scale *= 0.9;
	new = calc_zoomed_pix(zoom, *mouse);
	zoom->view_x += (temp.real - new.real);
	zoom->view_y += (temp.imag - new.imag);
}

void	zoom_out(t_cords *mouse, t_zoom *zoom)
{
	t_complx	temp;
	t_complx	new;

	temp = calc_zoomed_pix(zoom, *mouse);
	zoom->scale *= 1.1;
	new = calc_zoomed_pix(zoom, *mouse);
	zoom->view_x += (temp.real - new.real);
	zoom->view_y += (temp.imag - new.imag);
}
