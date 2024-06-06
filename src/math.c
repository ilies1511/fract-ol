/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iziane <iziane@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/02 01:28:15 by iziane            #+#    #+#             */
/*   Updated: 2024/06/07 00:54:10 by iziane           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

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

double	scale_map(double to_scale, t_params *f, double old_min, double old_max)
{
	return ((f->x_max - f->x_min) * (to_scale - old_min)
		/ (old_max - old_min) + f->x_min);
}

double	set_color(double to_scale, double old_min, double old_max)
{
	return ((BLACK - WHITE) * (to_scale - old_min)
		/ (old_max - old_min) + BLACK);
}
