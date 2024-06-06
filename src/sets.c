/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sets.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iziane <iziane@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/06 20:16:58 by iziane            #+#    #+#             */
/*   Updated: 2024/06/06 21:06:06 by iziane           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	complex_julia(t_params *fractol, int x, int y)
{
	fractol->c->x = fractol->julia->x;
	fractol->c->y = fractol->julia->y;
	fractol->z->x = scale_map(x, fractol, 0, WIDTH);
	fractol->z->y = scale_map(y, fractol, 0, HEIGHT);
}
//Nicht Normkonform: Stand 06.06.2024
// void	complex_julia(t_params *fractol, int x, int y)
// {
// 	fractol->c->x = fractol->julia->x;
// 	fractol->c->y = fractol->julia->y;
// 	fractol->z->x = scale_map(x, fractol->x_min, fractol->x_max, 0, WIDTH);
// 	fractol->z->y = scale_map(y, fractol->y_min, fractol->y_max, 0, HEIGHT);
// }

void	complex_mandel(t_params *fractol, int x, int y)
{
	fractol->z->x = 0;
	fractol->z->y = 0;
	fractol->c->x = scale_map(x, fractol, 0, WIDTH);
	fractol->c->y = scale_map(y, fractol, 0, HEIGHT);
}

//Nicht Normkonform: Stand 06.06.2024
// void	complex_mandel(t_params *fractol, int x, int y)
// {
// 	fractol->z->x = 0;
// 	fractol->z->y = 0;
// 	fractol->c->x = scale_map(x, fractol->x_min, fractol->x_max, 0, WIDTH);
// 	fractol->c->y = scale_map(y, fractol->y_max, fractol->y_min, 0, HEIGHT);
// }
