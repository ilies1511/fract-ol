/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pixel.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iziane <iziane@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/02 01:52:30 by iziane            #+#    #+#             */
/*   Updated: 2024/06/02 01:52:55 by iziane           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	pixel_manager(int x, int y, t_params *fractol)
{
	int		i;
	int		color;
	double	temp;
	double	z_x_squared;
	double	z_y_squared;

	fractol->z->x = 0; //(fractol->x_max + fractol->x_min) / 2;
	fractol->z->y = 0; //(fractol->y_max + fractol->y_min) / 2;;
	fractol->c->x = scale_map(x, fractol->x_min, fractol->x_max, 0, WIDTH);
	fractol->c->y = scale_map(y, fractol->y_max, fractol->y_min, 0, HEIGHT);
	i = 0;
	while (i < fractol->max_iter)
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
