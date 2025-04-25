/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zoom.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apregitz <apregitz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/13 20:08:54 by apregitz          #+#    #+#             */
/*   Updated: 2025/04/26 00:22:54 by apregitz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

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
