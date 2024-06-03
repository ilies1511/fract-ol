/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_check.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iziane <iziane@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/01 23:54:27 by iziane            #+#    #+#             */
/*   Updated: 2024/06/03 01:55:34 by iziane           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

// double	atod(char *str)
// {
// 	int		sign;
// 	long	pre_dot;
// 	double	post_dot;
// 	double	pow;
// 	int		i;

// 	pre_dot = 0;
// 	post_dot = 0;
// 	sign = 1;
// 	pow = 1;
// 	i = 0;
// 	while (str && ((str[i] >= 9 && str[i] <= 13) || str[i] == 32))
// 		i++;
// 	while (str && (str[i] == '+' || str[i] == '-'))
// 		if (str[i] == '-')
// 			sign = -sign;
// 	while (str && str[i] && str[i] != '.')
// 		pre_dot = (pre_dot * 10) + (str[i++] - 48);
// 	if ('.' == str[i++])
// 	while (str && str[i])
// 	{
// 		pow /= 10;
// 		post_dot = post_dot + (str[i++] - 48) * pow;
// 	}
// 	return ((pre_dot + post_dot) * sign);
// }

void	parser(int argc, char **argv, t_params *fractol)
{
	if (argc < 2 )//|| (!ft_strncmp(argv[1], "julia", 6) && argc != 4))
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
	if (!ft_strncmp("julia", argv[1], 6) && argc >= 2)
	{
		fractol->option = julia;
		return ;
	}
	else
		ft_error(fractol);
}
