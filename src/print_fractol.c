/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_fractol.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apregitz <apregitz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/25 22:11:56 by apregitz          #+#    #+#             */
/*   Updated: 2025/04/26 00:21:29 by apregitz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

void	print_fractol(t_data *data)
{
	t_cords		cords;
	t_complx	c;
	t_complx	z;

	z.imag = 0;
	z.real = 0;
	cords.y = 0;
	while (cords.y < data->zoom.win_height)
	{
		cords.x = 0;
		while (cords.x < data->zoom.win_width)
		{
			data->func_ptr(data, cords, &z, &c);
			cords.x++;
		}
		cords.y++;
	}
}
