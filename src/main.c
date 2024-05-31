/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iziane <iziane@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/30 21:25:39 by iziane            #+#    #+#             */
/*   Updated: 2024/05/31 22:19:46 by iziane           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	ft_color(t_params *fractol)
{
	(void)fractol;
	return (0);
}

t_cmplx_nbr	square_complex(t_cmplx_nbr z)
{
	t_cmplx_nbr	res;

	res.x = (z.x * z.x) - (z.y * z.y);
	res.y = 2 * z.x * z.y;
	return (res);
}

t_cmplx_nbr	sum_complex(t_cmplx_nbr z1, t_cmplx_nbr z2)
{
	t_cmplx_nbr	res;

	res.x = z1.x + z2.x;
	res.y = z1.y + z2.y;
	return (res);
}

double	scale_map(double unscaled_num, double new_min, double new_max, double old_min, double old_max)
{
	return ((new_max - new_min) * (unscaled_num - old_min) / (old_max - old_min) + new_min);
}

void	pixel_manager(int x, int y, t_params *fractol)
{
	int		i;
	int		color;
	double	temp;
	double	z_x_squared;
	double	z_y_squared;

	fractol->z->x = 0;
	fractol->z->y = 0;
	fractol->c->x = scale_map(x, -2, 2, 0, WIDTH);
	fractol->c->y = scale_map(y, 2, -2, 0, HEIGHT);
	i = 0;
	while (i < MAX_ITER)
	{
		z_x_squared = fractol->z->x * fractol->z->x;
		z_y_squared = fractol->z->y * fractol->z->y;
		if (z_x_squared + z_y_squared > fractol->escape_value)
		{
			color = scale_map(i, BLACK, WHITE, 0, MAX_ITER);
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

// void	pixel_manager(int x, int y, t_params *fractol)
// {
// 	t_cmplx_nbr	z;
// 	t_cmplx_nbr	c;
// 	int			i;
// 	int			color;

// 	c.x = scale_map(x, -2, +2, 0, WIDTH);
// 	c.y = scale_map(y, +2, -2, 0, HEIGHT);
// 	i = 0;
// 	while (i < MAX_ITER)
// 	{
// 		int s = (z.x * z.x) + (z.y * z.y);
// 		if (s > fractol->escape_value)
// 		{
// 			color = scale_map (i, BLACK, WHITE, 0, MAX_ITER);
// 			// printf("s: %d, %f\n", s, fractol->escape_value);
// 			mlx_put_pixel(fractol->img, fractol->coordinates.x, fractol->coordinates.y, BLACK);
// 			return ;
// 		}
// 		else
// 			mlx_put_pixel(fractol->img, fractol->coordinates.x, fractol->coordinates.y, RED);
// 		i++;
// 	}
// }

void	render(t_params *fractol)
{
	mlx_delete_image(fractol->mlx, fractol->img);
	fractol->img = mlx_new_image(fractol->mlx, WIDTH, HEIGHT);
	mlx_image_to_window(fractol->mlx, fractol->img, 0, 0);
	fractol->coordinates.y = 0;
	fractol->coordinates.x = 0;
	while (fractol->coordinates.y < HEIGHT)
	{
		fractol->coordinates.x = 0;
		while(fractol->coordinates.x < WIDTH)
		{
			//Je nachdem ob der Punkt im Set ist oder nicht bekommt er in  Pixel Manager eine bestimmte Farbe
			pixel_manager(fractol->coordinates.x, fractol->coordinates.y, fractol);
			fractol->coordinates.x++;
		}
		fractol->coordinates.y++;

	}
}

//TODO: muss man danach noch den fractol struct free ?
int	fractol_init(t_params *fractol)
{
	fractol->coordinates.x = 0;
	fractol->coordinates.y = 0;
	fractol->y_max = 2.0;
	fractol->x_max = 2.0;
	fractol->y_min = -2.0;
	fractol->x_min = -2.5;
	fractol->c = (t_cmplx_nbr *) malloc(sizeof(t_cmplx_nbr));
	fractol->z = (t_cmplx_nbr *) malloc(sizeof(t_cmplx_nbr));
	fractol->max_iter = 500;
	fractol->iter = 0;
	fractol->escape_value = 4.0;
	fractol->mlx = mlx_init(WIDTH, HEIGHT, "izi-fractol", false);
	fractol->img = mlx_new_image(fractol->mlx, WIDTH, HEIGHT);
	if (fractol->mlx && fractol->img)
		return (1);
	else
	{
		free(fractol);
		return(exit(EXIT_FAILURE), 0);
	}
}

void	ft_error(t_params *fractol)
{
	ft_putendl_fd("Error, wrong input !", 2);
	ft_putendl_fd("*************************************************", 2);
	ft_putendl_fd("Guide to usage:", 2);
	ft_putendl_fd("./fractol [option1] | [option2] | [option3]", 2);
	ft_putendl_fd("option1: ./fractol mandelbrot", 2);
	ft_putendl_fd("option2: ./fractol julia [parameter] [parameter]", 2);
	ft_putendl_fd("option3: ./fractol burningship", 2);
	free(fractol);
	exit(EXIT_FAILURE);
}

void	parser(int argc, char **argv, t_params *fractol)
{
	if (argc < 2 || (!ft_strncmp(argv[1], "julia", 6) && argc != 4))
		ft_error(fractol);
	if (argc > 4)
		ft_error(fractol);
	if (ft_strncmp(argv[1], "julia", 6)
		&& ft_strncmp(argv[1], "mandelbrot", 11))
		ft_error(fractol);
	if (!ft_strncmp("mandelbrot", argv[1], 11) && argc == 2)
	{
		fractol->option = mandelbrot;
		return ;
	}
	if (!ft_strncmp("julia", argv[1], 11) && argc == 4)
	{
		fractol->option = julia;
		return ;
	}
	else
		ft_error(fractol);
}

int	main(int argc, char **argv)
{
	t_params	*fractol;

	fractol = (t_params *)malloc(sizeof(t_params));
	parser(argc, argv, fractol);
	if (fractol_init(fractol))
		render(fractol);

	// mlx_loop_hook(fractol->mlx, ft_hook, mlx);
	mlx_loop(fractol->mlx);
	mlx_terminate(fractol->mlx);
	return (0);
}
