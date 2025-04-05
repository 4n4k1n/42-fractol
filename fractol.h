/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anakin <anakin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/03 20:43:01 by anakin            #+#    #+#             */
/*   Updated: 2025/04/05 06:02:44 by anakin           ###   ########.fr       */
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
#  define WIDTH 700
# endif

# ifndef HEIGHT
#  define HEIGHT 700
# endif

# ifndef MAX_ITER
#  define MAX_ITER 100
# endif

typedef struct s_complx
{
    double  real;
    double  imag;
}           t_complx;

typedef struct s_maped
{
    double  min_x;
    double  max_x;
    double  min_y;
    double  max_y;
}           t_maped;

typedef struct s_cords
{
    double  x;
    double  y;
}           t_cords;

#endif