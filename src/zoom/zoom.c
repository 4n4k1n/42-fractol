/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zoom.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apregitz <apregitz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/13 20:08:54 by apregitz          #+#    #+#             */
/*   Updated: 2025/04/25 22:23:14 by apregitz         ###   ########.fr       */
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
