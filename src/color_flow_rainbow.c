/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_flow_rainbow.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apregitz <apregitz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/25 22:27:52 by apregitz          #+#    #+#             */
/*   Updated: 2025/04/25 23:43:24 by apregitz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

int	rainbow(t_data *data, int i)
{
	int		r;
	int		g;
	int		b;
	double	zoom_factor;

	zoom_factor = -log10(data->zoom.scale) * 5;
	r = get_byte(i * (4 + sin(zoom_factor * 1.2) * 4));
	g = get_byte(i * (8 + sin(zoom_factor * 0.7) * 4));
	b = get_byte(i * (12 + sin(zoom_factor * 0.9) * 4));
	return (r << 24 | g << 16 | b << 8 | 0xf0);
}
