/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apregitz <apregitz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/25 21:35:34 by apregitz          #+#    #+#             */
/*   Updated: 2025/04/25 21:40:02 by apregitz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

void	init_rgb(t_rgb *rgb)
{
	rgb->rainbow = -1;
	rgb->mode = 0;
	rgb->r.color = 0.333;
	rgb->g.color = 0.666;
	rgb->b.color = 0.999;
	rgb->r.state = 1;
	rgb->g.state = 1;
	rgb->b.state = 1;
}