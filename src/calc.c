/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calc.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apregitz <apregitz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/13 20:11:02 by apregitz          #+#    #+#             */
/*   Updated: 2025/04/26 00:21:57 by apregitz         ###   ########.fr       */
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

t_complx	calc_zoomed_pix(t_zoom *zoom, t_cords cords)
{
	t_complx	new_cords;

	new_cords.real = (cords.x - (zoom->win_width / 2)) \
	* zoom->scale + zoom->view_x;
	new_cords.imag = (cords.y - (zoom->win_height / 2)) \
	* zoom->scale + zoom->view_y;
	return (new_cords);
}
