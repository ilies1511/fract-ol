/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iziane <iziane@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/07 00:36:27 by iziane            #+#    #+#             */
/*   Updated: 2024/06/07 00:38:39 by iziane           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	init_julia(t_params *fractol, char **argv, int argc)
{
	fractol->coordinates.x = 0;
	fractol->coordinates.y = 0;
	fractol->x_max = 2;
	fractol->y_max = 2;
	fractol->x_min = -2;
	fractol->y_min = -2;
	fractol->julia->x = -0.8;
	fractol->julia->y = 0.156;
	if (argc == 3)
		ft_free_all(fractol, 1);
	if (argc == 4)
	{
		fractol->julia->x = atod(argv[2]);
		fractol->julia->y = atod(argv[3]);
		if (fractol->julia->x < -2 || fractol->julia->x > 2)
			ft_free_all(fractol, 1);
		if (fractol->julia->y < -2 || fractol->julia->y > 2)
			ft_free_all(fractol, 1);
	}
}

void	init_mandelbrot(t_params *fractol)
{
	fractol->coordinates.x = 0;
	fractol->coordinates.y = 0;
	fractol->y_max = 2.0;
	fractol->x_max = 2.0;
	fractol->y_min = -2.0;
	fractol->x_min = -2.0;
}

int	fractol_init(t_params *fractol, char **argv, int argc)
{
	if (fractol->option == mandelbrot)
		init_mandelbrot(fractol);
	fractol->c = (t_cmplx_nbr *) malloc(sizeof(t_cmplx_nbr));
	fractol->z = (t_cmplx_nbr *) malloc(sizeof(t_cmplx_nbr));
	fractol->julia = (t_cmplx_nbr *) malloc(sizeof(t_cmplx_nbr));
	if (fractol->option == julia)
		init_julia(fractol, argv, argc);
	fractol->max_iter = 200;
	fractol->iter = 0;
	fractol->zoom = 0.05;
	fractol->escape_value = 4.0;
	fractol->mlx = mlx_init(WIDTH, HEIGHT, "izi-fractol", false);
	fractol->img = mlx_new_image(fractol->mlx, WIDTH, HEIGHT);
	if (fractol->mlx && fractol->img)
		return (1);
	else
		return (ft_free_all(fractol, 1), 0);
}
