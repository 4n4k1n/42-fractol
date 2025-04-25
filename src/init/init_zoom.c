/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_zoom.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apregitz <apregitz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/25 22:22:51 by apregitz          #+#    #+#             */
/*   Updated: 2025/04/25 22:23:07 by apregitz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../fractol.h"

void	init_zoom(t_zoom *zoom)
{
	zoom->scale = 0.0075;
	zoom->view_x = 0.0;
	zoom->view_y = 0.0;
	zoom->win_width = WIDTH;
	zoom->win_height = HEIGHT;
	zoom->mouse_status = 0;
}
