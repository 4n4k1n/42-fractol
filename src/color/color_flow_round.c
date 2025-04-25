/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_flow_round.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apregitz <apregitz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/25 22:26:00 by apregitz          #+#    #+#             */
/*   Updated: 2025/04/25 22:28:17 by apregitz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../fractol.h"

void	increase_color_part(t_color_byte *byte)
{
	if (byte->state)
	{
		byte->color += 0.05;
		if (byte->color + 0.05 > 1.0)
			byte->state = 0;
	}
	else
	{
		byte->color -= 0.05;
		if (byte->color - 0.05 < 0.0)
			byte->state = 1;
	}
}

void	color_flow(t_data *data)
{
	increase_color_part(&(data->rgb.r));
	increase_color_part(&(data->rgb.g));
	increase_color_part(&(data->rgb.b));
}
