/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calc.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apregitz <apregitz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/13 20:11:02 by apregitz          #+#    #+#             */
/*   Updated: 2025/04/20 11:48:07 by apregitz         ###   ########.fr       */
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

uint32_t	calc_byte(int i, int add)
{
	uint32_t	byte;

	byte = (255 + add) - ((i * 256) / MAX_ITER);
	return (byte);
}

uint32_t	calc_color(int i)
{
	uint32_t	color;

	if (i == MAX_ITER)
		return (0x000000ff);
	color = (((calc_byte(i, 100) << 24 | calc_byte(i, 120) << 16) | calc_byte(i, 80) << 8) | 0xff);
	return (color);
}

void	clac_pixel(t_complx z, t_complx c, t_cords cords, t_data *data)
{
	int			i;
	t_complx	temp;

	i = 0;
	while (pow(z.real, 2) + pow(z.imag, 2) < 4 && i < MAX_ITER)
	{
		temp.real = pow(z.real, 2) - pow(z.imag, 2) + c.real;
		temp.imag = 2 * z.real * z.imag + c.imag;
		z.real = temp.real;
		z.imag = temp.imag;
		i++;
	}
	mlx_put_pixel(data->img, cords.x, cords.y, calc_color(i));
}
