/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iziane <iziane@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/30 21:25:39 by iziane            #+#    #+#             */
/*   Updated: 2024/06/07 01:07:38 by iziane           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

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
		while (fractol->coordinates.x < WIDTH)
		{
			pixel_manager(fractol->coordinates.x,
				fractol->coordinates.y, fractol);
			fractol->coordinates.x++;
		}
		fractol->coordinates.y++;
	}
}

int	main(int argc, char **argv)
{
	t_params	*fractol;

	fractol = (t_params *)malloc(sizeof(t_params));
	parser(argc, argv, fractol);
	if (fractol_init(fractol, argv, argc))
		render(fractol);
	mlx_scroll_hook(fractol->mlx, &my_scrollhook, (void *)fractol);
	mlx_key_hook(fractol->mlx, &my_keyhook, (void *)fractol);
	mlx_loop(fractol->mlx);
	mlx_delete_image(fractol->mlx, fractol->img);
	mlx_terminate(fractol->mlx);
	ft_free_all(fractol, 7);
	return (0);
}

//Stand: 06.06.2024 20:57
// int	main(int argc, char **argv)
// {
// 	t_params	*fractol;

// 	fractol = (t_params *)malloc(sizeof(t_params));
// 	parser(argc, argv, fractol);
// 	if (fractol_init(fractol, argv))
// 		render(fractol);
// 	mlx_scroll_hook(fractol->mlx, &my_scrollhook, (void *)fractol);
// 	// mlx_image_to_window(fractol->mlx, fractol->img, 0, 0);
// 	mlx_key_hook(fractol->mlx, &my_keyhook, (void *)fractol);
// 	// mlx_loop_hook(fractol->mlx, &my_keyhook, (void *)fractol);
// 	mlx_loop(fractol->mlx);
// 	mlx_delete_image(fractol->mlx, fractol->img);
// 	mlx_terminate(fractol->mlx);
// 	return (0);
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
