/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iziane <iziane@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/02 00:11:08 by iziane            #+#    #+#             */
/*   Updated: 2024/06/06 22:56:09 by iziane           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	my_scrollhook(double xdelta, double ydelta, void *param)
{
	t_params	*fractol;
	mlx_t		*mlx;

	fractol = (t_params *)param;
	mlx = (mlx_t *)param;
	xdelta = 0;
	if (ydelta > 0)
	{
		fractol->x_min += (fractol->x_max - fractol->x_min) * fractol->zoom;
		fractol->x_max -= (fractol->x_max - fractol->x_min) * fractol->zoom;
		fractol->y_min += (fractol->y_max - fractol->y_min) * fractol->zoom;
		fractol->y_max -= (fractol->y_max - fractol->y_min) * fractol->zoom;
	}
	else
	{
		fractol->x_min -= (fractol->x_max - fractol->x_min) * fractol->zoom;
		fractol->x_max += (fractol->x_max - fractol->x_min) * fractol->zoom;
		fractol->y_min -= (fractol->y_max - fractol->y_min) * fractol->zoom;
		fractol->y_max += (fractol->y_max - fractol->y_min) * fractol->zoom;
	}
	render(fractol);
}

static void	move_vertical(mlx_key_data_t keydata, t_params *fractol)
{
	double	dif;

	if (keydata.key == MLX_KEY_W && keydata.action == MLX_RELEASE)
	{
		dif = (fractol->y_max - fractol->y_min);
		fractol->y_min -= dif * 0.05;
		fractol->y_max -= dif * 0.05;
	}
	if (keydata.key == MLX_KEY_S && keydata.action == MLX_RELEASE)
	{
		dif = (fractol->y_max - fractol->y_min);
		fractol->y_min += dif * 0.05;
		fractol->y_max += dif * 0.05;
	}
}

static void	move_horizontal(mlx_key_data_t keydata, t_params *fractol)
{
	double	dif;

	if (keydata.key == MLX_KEY_A && keydata.action == MLX_RELEASE)
	{
		dif = (fractol->x_max - fractol->x_min);
		fractol->x_min += dif * 0.05;
		fractol->x_max += dif * 0.05;
	}
	if (keydata.key == MLX_KEY_D && keydata.action == MLX_RELEASE)
	{
		dif = (fractol->x_max - fractol->x_min);
		fractol->x_min -= dif * 0.05;
		fractol->x_max -= dif * 0.05;
	}
}

void	my_keyhook(mlx_key_data_t keydata, void *param)
{
	t_params	*fractol;

	fractol = (t_params *)param;
	if (keydata.key == MLX_KEY_UP && keydata.action == MLX_RELEASE)
		fractol->max_iter++;
	if (keydata.key == MLX_KEY_DOWN && keydata.action == MLX_RELEASE)
		if (fractol->max_iter > 1)
			fractol->max_iter--;
	move_horizontal(keydata, fractol);
	move_vertical(keydata, fractol);
	if (keydata.key == MLX_KEY_ESCAPE && keydata.action == MLX_RELEASE)
	{
		mlx_delete_image(fractol->mlx, fractol->img);
		mlx_terminate(fractol->mlx);
		ft_free_all(fractol, 7);
		exit(MLX_SUCCESS);
	}
	render(fractol);
}
