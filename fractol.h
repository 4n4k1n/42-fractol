/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apregitz <apregitz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/03 20:43:01 by anakin            #+#    #+#             */
/*   Updated: 2025/04/11 22:46:10 by apregitz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "MLX42/include/MLX42/MLX42.h"
# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <math.h>

# define WIDTH 800
# define HEIGHT 800
# define MAX_ITER 100

typedef struct s_complx
{
	double	real;
	double	imag;
}	t_complx;

typedef struct s_cords
{
	int	x;
	int	y;
}	t_cords;

typedef struct s_maped
{
	double	min_x;
	double	max_x;
	double	min_y;
	double	max_y;
}	t_maped;

typedef struct s_zoom
{
    double  scale;          // Current zoom scale
    double  view_x;         // Viewpoint X coordinate
    double  view_y;         // Viewpoint Y coordinate
    int     win_width;      // Window width
    int     win_height;     // Window height
    int     mouse_pressed;  // Flag for mouse button state (for panning)
}   t_zoom;

typedef struct s_fractal_data
{
    mlx_t       *mlx;
    mlx_image_t *img;
    t_zoom      zoom;
} t_fractal_data;

// Function prototypes
t_complx	calculate_c(t_maped map, t_cords cords);
void	    calc_zoomed_pix(t_zoom *zoom, t_cords *cords, t_cords *new_cords);
void	    calculate_zoomed_map(t_zoom *zoom, t_maped *map);
void	    init_zoom(t_zoom *zoom);
void	    zoom_in(t_cords *mouse, t_zoom *zoom, t_cords *pixel);
void	    zoom_out(t_cords *mouse, t_zoom *zoom, t_cords *pixel);
void	    pan(t_zoom *zoom, int dx, int dy);
t_complx	calc_next_iter_num(t_complx z, t_complx c);
void	    init_mandelbrot_structs(t_maped *map, t_complx *complxx_num);
void	    clac_pixel(t_complx z, t_complx c, t_cords cords, mlx_image_t *img);
void        print_fractol(mlx_image_t *img, t_zoom *zoom);

#endif