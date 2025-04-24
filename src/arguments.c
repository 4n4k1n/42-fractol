/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arguments.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apregitz <apregitz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/20 10:55:14 by apregitz          #+#    #+#             */
/*   Updated: 2025/04/24 17:30:50 by apregitz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"
#include <stdio.h>

int init_mandelbrot(t_data *data)
{
	data->func_ptr = mandelbrot;
	return (1);
}

int	init_burningship(t_data *data)
{
	data->func_ptr = burningship;
	return (1);
}

t_complx	*get_set(void)
{
	static t_complx set;

	return (&set);
}

void	init_set(double real, double imag)
{
	t_complx *set;

	set = get_set();
	set->imag = imag;
	set->real = real;
}



int	init_julia_set(int ac, char **av, t_data *data)
{
	double real;
	double imag;

	real = 0;
	imag = 0;
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

int check_arguments(int ac, char **av, t_data *data)
{
	if (ac < 2)
		return (write(1, "Invalid amount of arguments!\n", 29), 0);
	else if (ft_strcmp("mandelbrot", av[1]) == 0)
		return (init_mandelbrot(data));
	else if (ft_strcmp("julia", av[1]) == 0)
		return (init_julia_set(ac, av, data));
	else if (ft_strcmp("burningship", av[1]) == 0)
		return (init_burningship(data));
	return (write(1, "Fractol not found!\n", 19), 0);
}
