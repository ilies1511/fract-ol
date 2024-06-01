/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_check.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iziane <iziane@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/01 23:54:27 by iziane            #+#    #+#             */
/*   Updated: 2024/06/02 00:04:07 by iziane           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

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
