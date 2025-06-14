/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apregitz <apregitz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/20 10:55:14 by apregitz          #+#    #+#             */
/*   Updated: 2025/04/27 11:03:54 by apregitz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

int	check_arguments(int ac, char **av, t_data *data)
{
	init_set(-0.7, 0.27015);
	if (ac < 2 || ac > 4)
	{
		write(1, "Invalid arguments!\n./fractol <name> <real> <imag>\n", 50);
		return (0);
	}
	else if (ft_strcmp("mandelbrot", av[1]) == 0 && ac == 2)
		return (init_mandelbrot(data));
	else if (ft_strcmp("julia", av[1]) == 0 && (ac >= 2 && ac <= 4))
	{
		if (init_julia_set(ac, av, data))
			return (1);
		write(1, "Invalid arguments!\n./fractol <name> <real> <imag>\n", 50);
		return (0);
	}
	else if (ft_strcmp("burningship", av[1]) == 0 && ac == 2)
		return (init_burningship(data));
	write(1, "Invalid arguments!\n./fractol <name> <real> <imag>\n", 50);
	return (0);
}
