/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_mandelbrot.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apregitz <apregitz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/25 22:16:47 by apregitz          #+#    #+#             */
/*   Updated: 2025/04/25 22:45:42 by apregitz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../fractol.h"

int	init_mandelbrot(t_data *data)
{
	data->func_ptr_index = 0;
	data->func_ptr = mandelbrot;
	return (1);
}
