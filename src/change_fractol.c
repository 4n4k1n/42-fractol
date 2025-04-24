/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   change_fractol.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apregitz <apregitz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/24 17:57:52 by apregitz          #+#    #+#             */
/*   Updated: 2025/04/24 21:19:13 by apregitz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

void change_fractol(t_data *data)
{
    static const t_func_ptr func_ptr[3] = {mandelbrot, julia, burningship};
    
    data->func_ptr_index += 1;
    if (data->func_ptr_index == 3)
    data->func_ptr_index = 0;
    data->func_ptr = func_ptr[data->func_ptr_index];
}
