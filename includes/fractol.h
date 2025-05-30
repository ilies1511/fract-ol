/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iziane <iziane@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/27 20:28:33 by iziane            #+#    #+#             */
/*   Updated: 2024/06/07 00:38:45 by iziane           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "libft.h"
# include "MLX42.h"
# include <unistd.h>
# include <stdio.h>
# include <stdbool.h>
# include <math.h> // Mathe Lib
# include <fcntl.h> // fuer open
# include <stdlib.h>
# define WIDTH 800
# define HEIGHT 800
# define MAX_ITER 200
# define ZOOM 3
# define BLACK 0x000000
# define WHITE 0xFFFFFF
# define RED 0xFF0000FF

// typedef struct mlx_key_data
// {
// 	keys_t			key;
// 	action_t		action;
// 	int32_t			os_key;
// 	modifier_key_t	modifier;
// }					mlx_key_data_t;

typedef struct s_color
{
	int	black;
	int	white;
}		t_color;

typedef struct s_cmplx_nbr
{
	double	x;
	double	y;
}		t_cmplx_nbr;

typedef struct s_point
{
	int	x;
	int	y;
}		t_point;

typedef enum e_fractal_options
{
	mandelbrot,
	julia,
	burning_ship,
}		t_which_fractal;
/*
Zentrale, beinhaltet alle Informationen bezüglich dees Stucts
*/
typedef struct s_params
{
	mlx_t			*mlx;
	mlx_image_t		*img;
	int				max_iter;
	double			zoom;
	double			x_max;
	double			x_min;
	double			y_max;
	double			y_min;
	t_cmplx_nbr		*z;
	t_cmplx_nbr		*c;
	t_cmplx_nbr		*julia;
	int				iter;
	int				r;
	int				g;
	int				b;
	double			escape_value;
	int				color_scheme;
	t_point			coordinates;
	t_which_fractal	option;
}					t_params;

////////////////////////////////// Functions //////////////////////////////
//Parser
void		parser(int argc, char **argv, t_params *fractol);
void		ft_error(t_params *fractol);
double		atod(char *str);
//Init
int			fractol_init(t_params *fractol, char **argv, int argc);
void		init_mandelbrot(t_params *fractol);
void		init_julia(t_params *fractol, char **argv, int argc);
//Hooks
void		my_keyhook(mlx_key_data_t keydata, void *param);
void		my_scrollhook(double xdelta, double ydelta, void *param);
//Render
void		render(t_params *fractol);
//Error
void		ft_error(t_params *fractol);
void		ft_free_all(t_params *fractol, int flag);
//Math
t_cmplx_nbr	square_complex(t_cmplx_nbr z);
t_cmplx_nbr	sum_complex(t_cmplx_nbr z1, t_cmplx_nbr z2);
double		scale_map(double unscaled_num, t_params *f,
				double old_min, double old_max);
//Pixel
void		pixel_manager(int x, int y, t_params *fractol);
void		type_converter(t_params *fractol, int x, int y);
void		complex_mandel(t_params *fractol, int x, int y);
void		complex_julia(t_params *fractol, int x, int y);
//Color
double		set_color(double to_scale, double old_min, double old_max);

#endif

// double		scale_map(double unscaled_num, double
//	new_min, double new_max, double old_min, double old_max);
