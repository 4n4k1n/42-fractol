/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apregitz <apregitz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/25 22:29:43 by apregitz          #+#    #+#             */
/*   Updated: 2025/04/25 23:43:33 by apregitz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

int	get_byte(double i)
{
	return ((i * 255 / MAX_ITER));
}

int	get_color(int i, t_data *data)
{
	int	color;

	if (i == MAX_ITER)
		return (0x000000ff);
	else if (data->rgb.rainbow == 't')
		return (255 << 24 | 0 << 16 | 0 << 8 | 0xf0);
	if (data->rgb.rainbow == 1)
		return (rainbow(data, i));
	color = (get_byte(i * data->rgb.r.color) << 24 \
	| get_byte(i * data->rgb.g.color) << 16 \
	| get_byte(i * data->rgb.b.color) << 8 | 0xf0);
	return (color);
}
