/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anakin <anakin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/03 20:43:01 by anakin            #+#    #+#             */
/*   Updated: 2025/04/03 21:30:09 by anakin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "MLX42/include/MLX42/MLX42.h"
# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <math.h>

# ifndef WIDTH
#  define WIDTH 256
# endif

# ifndef HEIGHT
#  define HEIGHT 256
# endif

typedef struct s_complx
{
    double  real;
    double  imag;
}           t_complx;

#endif