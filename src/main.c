/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anakin <anakin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/02 21:00:05 by anakin            #+#    #+#             */
/*   Updated: 2025/04/03 21:42:48 by anakin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

int	check_set(double real, double imag, int iter, int max_iter)
{
	if (pow(real, 2) + pow(imag, 2) < 4 && iter < max_iter)
		return (1);
	return (0);
}


t_complx	calc_next_complx_num(t_complx old_complx, t_complx complx)
{
	t_complx	new_complx;

	new_complx.real = pow(old_complx.real, 2) - pow(old_complx.imag, 2) + complx.real;
	new_complx.imag = old_complx.real * old_complx.imag +complx.imag;
	return (new_complx);
}

void	print_fractol(int height, int width, void (*f)(void *))
{
	int	i;
	int	j;

	i = 0;
	while (i < height)
	{
		j = 0;
		while (j < width)
		{
			
		}
	}
}


int32_t	main(int ac, char **av)
{
	mlx_set_setting(MLX_MAXIMIZED, true);
	mlx_t* mlx = mlx_init(WIDTH, HEIGHT, "42Balls", true);
	if (!mlx)
		return (1);
	mlx_image_t* img = mlx_new_image(mlx, 256, 256);
	if (!img || (mlx_image_to_window(mlx, img, 0, 0) < 0))
		return (free(mlx), free(img), 1);
	mlx_terminate(mlx);
	return (EXIT_SUCCESS);
}