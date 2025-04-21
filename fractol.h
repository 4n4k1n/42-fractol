/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apregitz <apregitz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/03 20:43:01 by anakin            #+#    #+#             */
/*   Updated: 2025/04/21 18:47:33 by apregitz         ###   ########.fr       */
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
#  define WIDTH 500
# endif

# ifndef HEIGHT
#  define HEIGHT 500
#endif

# ifndef MAX_ITER
#  define MAX_ITER 256
# endif

typedef struct s_complx
{
	double	real;
	double	imag;
}			t_complx;

typedef struct s_cords
{
	int	x;
	int	y;
}		t_cords;

typedef struct s_zoom
{
	double	scale;
	double	view_x;
	double	view_y;
	int		win_width;
	int		win_height;
	int		mouse_status;
}			t_zoom;

typedef struct s_rgb
{
	int			r;
	int			g;
	int			b;
	uint32_t	color;
}		t_rgb;

struct s_data;

typedef void (*t_func_ptr)(struct s_data *, t_cords, t_complx *, t_complx *);

typedef struct s_data
{
    mlx_t       *mlx;
    mlx_image_t *img;
    t_zoom      zoom;
    t_rgb       rgb;
    t_func_ptr  func_ptr;
}               t_data;

// helpers
int			ft_strcmp(const char *s1, const char *s2);
int			ft_atof(char *str, double *result);

// fractol functions
int			check_arguments(int ac, char **av, t_data *data);
t_complx	calc_zoomed_pix(t_zoom *zoom, t_cords cords);
void		init_zoom(t_zoom *zoom);
void		zoom_in(t_cords *mouse, t_zoom *zoom);
void		zoom_out(t_cords *mouse, t_zoom *zoom);
t_complx	calc_next_iter_num(t_complx z, t_complx c);
void		clac_pixel(t_complx z, t_complx c, t_cords cords, t_data *img);
void		print_fractol(t_data *data);

// hooks
void		key_zoom_hook(mlx_key_data_t keydata, void *param);
void		resize_window(int32_t width, int32_t height, void *param);

// functions for func ptr
void		mandelbrot(t_data *data, t_cords cords, t_complx *z, t_complx *c);
void		julia(t_data *data, t_cords cords, t_complx *z, t_complx *c);

// functions to store the complex nbr
t_complx	*get_set(void);
void		init_set(double real, double imag);

#endif