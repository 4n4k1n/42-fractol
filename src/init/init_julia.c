/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_julia.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apregitz <apregitz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/25 22:14:13 by apregitz          #+#    #+#             */
/*   Updated: 2025/04/25 22:14:57 by apregitz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../fractol.h"

int	init_julia_set(int ac, char **av, t_data *data)
{
	double real;
	double imag;

	real = 0;
	imag = 0;
	data->func_ptr_index = 1;
	data->func_ptr = julia;
	if (ac == 3 || ac == 4)
	{
		if (!ft_atof(av[2], &real))
			return (write(1, "Invalid argument!\n", 18), 0);
		if (ac == 4)
		{
			if (!ft_atof(av[3], &imag))
				return (write(1, "Invalid argument!\n", 18), 0);
			init_set(real, imag);
		}
		else
			init_set(real, 0.27015);
	}
	else
		init_set(-0.7, 0.27015);
	return (1);
}
