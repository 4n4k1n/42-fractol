/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apregitz <apregitz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/03 20:43:01 by anakin            #+#    #+#             */
/*   Updated: 2025/04/26 00:27:14 by apregitz         ###   ########.fr       */
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
#  define MAX_ITER 128
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

typedef struct s_color_byte
{
	double	color;
	int		state;
}			t_color_byte;

typedef struct s_rgb
{
	t_color_byte	r;
	t_color_byte	g;
	t_color_byte	b;
	int				rainbow;
	int				mode;
}					t_rgb;

struct s_data;

typedef void (*t_func_ptr)(struct s_data *, t_cords, t_complx *, t_complx *);

typedef struct s_data
{
    mlx_t       *mlx;
    mlx_image_t *img;
    t_zoom      zoom;
    t_rgb       rgb;
    t_func_ptr  func_ptr;
	int			func_ptr_index;
}               t_data;

// math
t_complx	calc_next_iter_num(t_complx z, t_complx c);
void		clac_pixel(t_complx z, t_complx c, t_cords cords, t_data *data);
t_complx	calc_zoomed_pix(t_zoom *zoom, t_cords cords);

// key hook helper
void		change_fractol(t_data *data);

// color
int			rainbow(t_data *data, int i);
void		increase_color_part(t_color_byte *byte);
void		color_flow(t_data *data);
int			get_byte(double i);
int			get_color(int i, t_data *data);

// helpers
int			ft_atof(char *str, double *result);
int			ft_strcmp(const char *s1, const char *s2);

// fractols
void		mandelbrot(t_data *data, t_cords cords, t_complx *z, t_complx *c);
void		julia(t_data *data, t_cords cords, t_complx *z, t_complx *c);
void		burningship(t_data *data, t_cords cords, t_complx *z, t_complx *c);

// init
int			init_burningship(t_data *data);
int			init_julia_set(int ac, char **av, t_data *data);
int			init_mandelbrot(t_data *data);
void		init_rgb(t_rgb *rgb);
void		init_set(double real, double imag);
void		init_zoom(t_zoom *zoom);

// set getter
t_complx	*get_set(void);

// hooks
void		key_hook(mlx_key_data_t keys, void *param);
void		scroll_hook(double x_state, double y_state, void *param);
void		resize_window_hook(int32_t width, int32_t height, void *param);

// parsing
int			check_arguments(int ac, char **av, t_data *data);

// print
void		print_fractol(t_data *data);

// zoom
void		zoom_in(t_cords *mouse, t_zoom *zoom);
void		zoom_out(t_cords *mouse, t_zoom *zoom);

#endif