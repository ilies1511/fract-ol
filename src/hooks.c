/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iziane <iziane@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/02 00:11:08 by iziane            #+#    #+#             */
/*   Updated: 2024/06/02 01:05:34 by iziane           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	my_keyhook(mlx_key_data_t keydata, void *param)
{
	t_params	*fractol;
	double		dif;

	fractol = (t_params *)param;
	if (keydata.key == MLX_KEY_UP && keydata.action == MLX_RELEASE)
		fractol->max_iter++;
	if (keydata.key == MLX_KEY_DOWN && keydata.action == MLX_RELEASE)
		if (fractol->max_iter > 1)
			fractol->max_iter--;
	//TODO: Keyhooks for Moviing the whole Mandelbrot
	if (keydata.key == MLX_KEY_D && keydata.action == MLX_RELEASE)
	{
		dif = (fractol->y_max - fractol->y_min);
		fractol->y_min += dif * 0.05;
		fractol->y_max += dif * 0.05;
	}
	if (keydata.key == MLX_KEY_A && keydata.action == MLX_RELEASE)
	{
		dif = (fractol->y_max - fractol->y_min);
		fractol->y_min -= dif * 0.05;
		fractol->y_max -= dif * 0.05;
	}
	if (keydata.key == MLX_KEY_W && keydata.action == MLX_RELEASE)
	{
		dif = (fractol->x_max - fractol->x_min);
		fractol->x_min -= dif * 0.05;
		fractol->x_max -= dif * 0.05;
	}
	if (keydata.key == MLX_KEY_S && keydata.action == MLX_RELEASE)
	{
		dif = (fractol->x_max - fractol->x_min);
		fractol->x_min += dif * 0.05;
		fractol->x_max += dif * 0.05;
	}
	render(fractol);
}
