/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calc.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apregitz <apregitz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/13 20:11:02 by apregitz          #+#    #+#             */
/*   Updated: 2025/04/23 15:21:19 by apregitz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

t_complx	calc_next_iter_num(t_complx z, t_complx c)
{
	t_complx	new_z;

	new_z.real = pow(z.real, 2) - pow(z.imag, 2) + c.real;
	new_z.imag = z.real * z.imag + c.imag;
	return (new_z);
}

static int get_byte(double i)
{
	return ((i * 255 / MAX_ITER));
}

static int	rainbow(t_data *data, int i)
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

int	get_color(int i, t_data *data)
{
	int	color;

	if (i == MAX_ITER || i == 1)
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

void	clac_pixel(t_complx z, t_complx c, t_cords cords, t_data *data)
{
	int			i;
	t_complx	temp;

	i = -1;
	while (pow(z.real, 2) + pow(z.imag, 2) < 4 && ++i < MAX_ITER)
	{
		temp.real = pow(z.real, 2) - pow(z.imag, 2) + c.real;
		temp.imag = 2 * z.real * z.imag + c.imag;
		z.real = temp.real;
		z.imag = temp.imag;
	}
	mlx_put_pixel(data->img, cords.x, cords.y, get_color(i, data));
}
