/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apregitz <apregitz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/20 10:55:14 by apregitz          #+#    #+#             */
/*   Updated: 2025/04/25 22:19:39 by apregitz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

int check_arguments(int ac, char **av, t_data *data)
{
	init_set(-0.7, 0.27015);
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
