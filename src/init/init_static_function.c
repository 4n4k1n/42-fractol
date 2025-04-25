/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_static_function.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apregitz <apregitz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/25 22:16:00 by apregitz          #+#    #+#             */
/*   Updated: 2025/04/25 22:16:15 by apregitz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../fractol.h"

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
