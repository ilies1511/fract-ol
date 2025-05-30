/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pixel.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iziane <iziane@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/02 01:52:30 by iziane            #+#    #+#             */
/*   Updated: 2024/06/06 23:00:37 by iziane           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	type_converter(t_params *fractol, int x, int y)
{
	if (fractol->option == mandelbrot)
		complex_mandel(fractol, x, y);
	else if (fractol->option == julia)
		complex_julia(fractol, x, y);
}

void	pixel_manager(int x, int y, t_params *fractol)
{
	int		i;
	int		color;
	double	temp;
	double	z_x_squared;
	double	z_y_squared;

	type_converter(fractol, x, y);
	i = 0;
	while (i < fractol->max_iter)
	{
		z_x_squared = fractol->z->x * fractol->z->x;
		z_y_squared = fractol->z->y * fractol->z->y;
		if (z_x_squared + z_y_squared > fractol->escape_value)
		{
			color = set_color(i, 0, fractol->max_iter);
			mlx_put_pixel(fractol->img, x, y, color);
			return ;
		}
		temp = z_x_squared - z_y_squared + fractol->c->x;
		fractol->z->y = 2 * fractol->z->x * fractol->z->y + fractol->c->y;
		fractol->z->x = temp;
		i++;
	}
	mlx_put_pixel(fractol->img, x, y, BLACK);
}
// void	draw_mandelbrot(t_params *fractol, int x, int y, int i)
// {
// 	double	z_x_squared;
// 	double	z_y_squared;
// 	// int		i;
// 	int		color;
// 	double	temp;

// 	z_x_squared = fractol->z->x * fractol->z->x;
// 	z_y_squared = fractol->z->y * fractol->z->y;
// 	if (z_x_squared + z_y_squared > fractol->escape_value)
// 	{
// 		color = scale_map(i, BLACK, WHITE, 0, MAX_ITER);
// 		mlx_put_pixel(fractol->img, x, y, color);
// 		return ;
// 	}
// 	temp = z_x_squared - z_y_squared + fractol->c->x;
// 	fractol->z->y = 2 * fractol->z->x * fractol->z->y + fractol->c->y;
// 	fractol->z->x = temp;
// 	// i++;
// }

// static double	julia_func(t_params *fractol)
// {
// 	int		iter;
// 	double	z_real;
// 	double	z_imag;
// 	double	z_real_temp;
// 	double	z_imag_temp;

// 	iter = 0;
// 	z_real = fractol->z->x;
// 	z_imag = fractol->z->y;
// 	while (iter < fractol->max_iter)
// 	{
// 		z_real_temp = z_real * z_real - z_imag * z_imag + fractol->c->x;
// 		z_imag_temp = 2 * z_real * z_imag + fractol->c->y;
// 		z_real = z_real_temp;
// 		z_imag = z_imag_temp;
// 		if ((z_real * z_real + z_imag * z_imag) > 4.0)
// 			break ;
// 		iter++;
// 	}
// 	return (iter);
// }

// static void	type_converter(t_cmplx_nbr *z, t_cmplx_nbr *c,
		// t_params *fractal)
// {
// 	if (fractal->option == julia)
// 	{
// 		c->x = fractal->julia->x;
// 		c->y = fractal->julia->y;
// 	}
// 	else
// 	{
// 		c->x = z->x;
// 		c->y = z->y;
// 	}
// }

//Voll funktionsfaehig, aber nicht Clean Code
// void	pixel_manager_julia(int x, int y, t_params *fractol)
// {
// 	int		i;
// 	int		color;
// 	double	temp;
// 	double	z_x_squared;
// 	double	z_y_squared;

// 	i = 0;
// 	type_converter(fractol, x, y);
// 	temp = 0;
// 	while (i < MAX_ITER)
// 	{
// 		z_x_squared = fractol->z->x * fractol->z->x;
// 		z_y_squared = fractol->z->y * fractol->z->y;
// 		if (z_x_squared + z_y_squared > fractol->escape_value)
// 		{
// 			color = scale_map(i, BLACK, WHITE, 0, fractol->max_iter);
// 			mlx_put_pixel(fractol->img, x, y, color);
// 			return ;
// 		}
// 		temp = z_x_squared - z_y_squared + fractol->julia->x;
// 		fractol->z->y = 2 * fractol->z->x * fractol->z->y + fractol->julia->y;
// 		fractol->z->x = temp;
// 		i++;
// 	}
// 	mlx_put_pixel(fractol->img, x, y, BLACK);
// }

// //Different Fractol Sets
// void	complex_julia(t_params *fractol, int x, int y)
// {
// 	fractol->c->x = fractol->julia->x;
// 	fractol->c->y = fractol->julia->y;
// 	fractol->z->x = scale_map(x, fractol->x_min, fractol->x_max, 0, WIDTH);
// 	fractol->z->y = scale_map(y, fractol->y_min, fractol->y_max, 0, HEIGHT);
// }

// void	complex_mandel(t_params *fractol, int x, int y)
// {
// 	fractol->z->x = 0;
// 	fractol->z->y = 0;
// 	fractol->c->x = scale_map(x, fractol->x_min, fractol->x_max, 0, WIDTH);
// 	fractol->c->y = scale_map(y, fractol->y_max, fractol->y_min, 0, HEIGHT);
// }

// void	pixel_manager(int x, int y, t_params *fractol)
// {
// 	int		i;
// 	int		color;
// 	double	temp;
// 	double	z_x_squared;
// 	double	z_y_squared;

// 	fractol->z->x = 0; //(fractol->x_max + fractol->x_min) / 2;
// 	fractol->z->y = 0; //(fractol->y_max + fractol->y_min) / 2;;
// 	fractol->c->x = scale_map(x, fractol->x_min, fractol->x_max, 0, WIDTH);
// 	fractol->c->y = scale_map(y, fractol->y_max, fractol->y_min, 0, HEIGHT);
// 	i = 0;
// 	while (i < fractol->max_iter)
// 	{
// 		z_x_squared = fractol->z->x * fractol->z->x;
// 		z_y_squared = fractol->z->y * fractol->z->y;
// 		if (z_x_squared + z_y_squared > fractol->escape_value)
// 		{
// 			color = scale_map(i, BLACK, WHITE, 0, MAX_ITER);
// 			mlx_put_pixel(fractol->img, x, y, color);
// 			return ;
// 		}
// 		temp = z_x_squared - z_y_squared + fractol->c->x;
// 		fractol->z->y = 2 * fractol->z->x * fractol->z->y + fractol->c->y;
// 		fractol->z->x = temp;
// 		i++;
// 	}
// 	mlx_put_pixel(fractol->img, x, y, BLACK);
// }

// Pre change
// void	pixel_manager(int x, int y, t_params *fractol)
// {
// 	int		i;
// 	int		color;
// 	double	temp;
// 	double	z_x_squared;
// 	double	z_y_squared;
// 	double	c_x_squared;
// 	double	c_y_squared;

// 	fractol->z->x = 0;
// 	fractol->z->y = 0;
// 	fractol->c->x = scale_map(x, fractol->x_min, fractol->x_max, 0, WIDTH);
// 	fractol->c->y = scale_map(y, fractol->y_max, fractol->y_min, 0, HEIGHT);
// 	i = 0;
// 	while (i < fractol->max_iter)
// 	{
// 		if (fractol->option == mandelbrot)
// 		{
// 			z_x_squared = fractol->z->x * fractol->z->x;
// 			z_y_squared = fractol->z->y * fractol->z->y;
// 			if (z_x_squared + z_y_squared > fractol->escape_value)
// 			{
// 				color = scale_map(i, BLACK, WHITE, 0, fractol->max_iter);
// 				mlx_put_pixel(fractol->img, x, y, color);
// 				return ;
// 			}
// 			temp = z_x_squared - z_y_squared + fractol->c->x;
// 			fractol->z->y = 2 * fractol->z->x * fractol->z->y + fractol->c->y;
// 			fractol->z->x = temp;
// 			i++;
// 		}
// 		if (fractol->option == julia)
// 		{
// 			c_x_squared = fractol->c->x * fractol->c->x;
// 			c_y_squared = fractol->c->y * fractol->c->y;
// 			if (c_x_squared + c_y_squared > fractol->escape_value)
// 			{
// 				color = scale_map(i, BLACK, WHITE, 0, fractol->max_iter);
// 				mlx_put_pixel(fractol->img, x, y, color);
// 				return ;
// 			}
// 			temp = c_x_squared - c_y_squared + fractol->z->x;
// 			fractol->c->y = 2 * fractol->c->x * fractol->c->y + fractol->z->y;
// 			fractol->c->x = temp;
// 			i++;
// 		}
// 	}
// 	mlx_put_pixel(fractol->img, x, y, BLACK);
// }
