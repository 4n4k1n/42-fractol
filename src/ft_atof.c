/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atof.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apregitz <apregitz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/21 16:56:13 by apregitz          #+#    #+#             */
/*   Updated: 2025/06/01 11:10:13 by apregitz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

int	ft_atof(char *str, double *result)
{
	int		digits;
	int		sign;

	sign = 1;
	if (*str == '+' || *str == '-')
		sign = 1 - 2 * (*(str++) == '-');
	while (*str >= '0' && *str <= '9')
		*result = (*result * 10) + ((*(str++) - '0') * sign);
	if (*str == '\0')
		return (1);
	else if (*str == '.')
		str++;
	else
		return (0);
	digits = 1;
	while (*str >= '0' && *str <= '9')
	{
		*result = (*result * 10) + ((*(str++) - '0') * sign);
		digits *= 10;
	}
	if (*str == '\0')
		*result = (*result) / digits;
	else
		return (0);
	return (1);
}
