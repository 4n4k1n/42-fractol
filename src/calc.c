/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calc.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apregitz <apregitz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/13 20:11:02 by apregitz          #+#    #+#             */
/*   Updated: 2025/04/22 04:20:39 by apregitz         ###   ########.fr       */
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

int get_byte(int i)
{
	return ((i * 255 / MAX_ITER));
}

int	get_color(int i, t_data *data)
{
	double	zoom_factor;
	t_rgb	color;

	if (i == MAX_ITER)
		return (0x000000ff);
	if (data->rgb.rainbow == 1)
	{
		zoom_factor = -log10(data->zoom.scale) * 5;
		color.r = get_byte(i * (4 + sin(zoom_factor * 1.2) * 4));
		color.g = get_byte(i * (8 + cos(zoom_factor * 0.7) * 4));
		color.b = get_byte(i * (12 + sin(zoom_factor * 0.9) * 4));
		return (color.r << 24 | color.g << 16 | color.b << 8 | 0xf0);
	}
	return (get_byte(i) << 24 | get_byte(i) << 16 | get_byte(i) << 8 | 0xf0);
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
