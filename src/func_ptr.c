/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   func_ptr.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apregitz <apregitz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/20 13:28:57 by apregitz          #+#    #+#             */
/*   Updated: 2025/04/24 21:33:14 by apregitz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

void	mandelbrot(t_data *data, t_cords cords, t_complx *z, t_complx *c)
{
	*c = calc_zoomed_pix(&data->zoom, cords);
	clac_pixel(*z, *c, cords, data);
}

void	julia(t_data *data, t_cords cords, t_complx *z, t_complx *c)
{
	*z = calc_zoomed_pix(&data->zoom, cords);
	c = get_set();
	clac_pixel(*z, *c, cords, data);
}

void	burningship(t_data *data, t_cords cords, t_complx *z, t_complx *c)
{
	int			i;
	t_complx	temp;

	*c = calc_zoomed_pix(&data->zoom, cords);
	z->real = 0;
	z->imag = 0;
	i = 0;
	while (pow(z->real, 2) + pow(z->imag, 2) < 4 && i < MAX_ITER)
	{
		temp.real = pow(z->real, 2) - pow(z->imag, 2) + c->real;
		temp.imag = 2 * fabs(z->real * z->imag) + c->imag;
		z->real = fabs(temp.real);
		z->imag = fabs(temp.imag);
		i++;
	}
	mlx_put_pixel(data->img, cords.x, cords.y, get_color(i, data));
}
