/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arguments.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apregitz <apregitz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/20 10:55:14 by apregitz          #+#    #+#             */
/*   Updated: 2025/04/20 16:10:35 by apregitz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

int	ft_strcmp(const char *s1, const char *s2)
{
	int i;

	i = 0;
	while (s1[i] && s2[i])
	{
		if (s1[i] != s2[i])
			return (s1[i] - s2[i]);
		i++;
	}
	if (s1[i] != s2[i])
		return (s1[i] - s2[i]);
	return (0);
}

int check_arguments(int ac, char **av, t_data *data)
{
	if (ac < 2 || ac > 2)
		return (write(1, "Invalid amount of arguments!\n", 29), 0);
	else if (ft_strcmp("mandelbrot", av[1]) == 0)
		data->func_ptr = mandelbrot;
	else if (ft_strcmp("julia", av[1]) == 0)
		data->func_ptr = julia;
	else
		return (write(1, "Fractol not found!\n", 19), 0);
	return (1);
}
