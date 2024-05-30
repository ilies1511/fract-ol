/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iziane <iziane@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/27 20:28:33 by iziane            #+#    #+#             */
/*   Updated: 2024/05/30 22:39:24 by iziane           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "../libft/libft.h"
# include "../MLX42/include/MLX42/MLX42.h"
# include <unistd.h>
// # include "/Users/iziane/42/repo_fractol/fract-ol/MLX42/include/MLX42/MLX42.h"
# include <stdio.h>
# include <stdbool.h>
# include <math.h> // Mathe Lib
# include <fcntl.h> // fuer open
# include <stdlib.h>
# define WIDTH 256
# define HEIGHT 256
# define MAX_ITER 100
# define ZOOM 3

// typedef struct mlx_key_data
// {
// 	keys_t			key;
// 	action_t		action;
// 	int32_t			os_key;
// 	modifier_key_t	modifier;
// }					mlx_key_data_t;

typedef struct s_point
{
	int	x;
	int	y;
}		t_point;
/*
Carrries Important Data in regard to window,
context, width, height, delat_time
*/
typedef struct s_mlx
{
	void		*window;
	void		*context;
	int32_t		width;
	int32_t		height;
	double		delta_time;
}				t_mlx;

// void	fractol_maker(t_params *fractol)

typedef enum e_fractal_options
{
	mandelbrot,
	julia,
	burning_ship,
}		t_which_fractal;

typedef struct s_mlx_image
{
	const uint32_t	width;
	const uint32_t	height;
	uint8_t*		pixels;
	mlx_instance_t	*instances;
	size_t			count;
	bool			enabled;
	void*			context;
}					t_mlx_image;

/*
Zentrale, beinhaltet alle Informationen bezüglich dees Stucts
*/
typedef struct s_params
{
	t_which_fractal	option;
	t_mlx			*window; //ptr to window struct
	//Image
	t_mlx_image		*image; //ptr to window struct
	int				bpp; //Bites per Pixel
	//Init Fractol
	int				max_iter;
	double			zoom;
	t_point			coordinates;
}					t_params;

////////////////////////////////// Functions //////////////////////////////
//Init
void	frinitialisation(t_params *fractol);
void	fractol_maker(t_params *fractol);

#endif
