/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   func_ptr.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apregitz <apregitz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/20 13:28:57 by apregitz          #+#    #+#             */
/*   Updated: 2025/04/21 16:51:09 by apregitz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

void mandelbrot(t_data *data, t_cords cords, t_complx *z, t_complx *c)
{
	*c = calc_zoomed_pix(&data->zoom, cords);
	clac_pixel(*z, *c, cords, data);
}

void julia(t_data *data, t_cords cords, t_complx *z, t_complx *c)
{
	*z = calc_zoomed_pix(&data->zoom, cords);
	c = get_set();
	clac_pixel(*z, *c, cords, data);
}
