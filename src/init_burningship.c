/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_burningship.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apregitz <apregitz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/25 22:17:37 by apregitz          #+#    #+#             */
/*   Updated: 2025/04/25 23:43:44 by apregitz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

int	init_burningship(t_data *data)
{
	data->func_ptr_index = 1;
	data->func_ptr = burningship;
	return (1);
}
