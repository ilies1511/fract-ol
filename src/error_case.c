/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_case.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iziane <iziane@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/02 00:27:15 by iziane            #+#    #+#             */
/*   Updated: 2024/06/07 00:43:38 by iziane           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	ft_free_all(t_params *fractol, int flag)
{
	free(fractol->z);
	free(fractol->c);
	free(fractol->julia);
	if (flag == 1)
		ft_error(fractol);
	free(fractol);
	if (flag == 7)
		exit(EXIT_SUCCESS);
	exit(EXIT_FAILURE);
}

void	ft_error(t_params *fractol)
{
	ft_putendl_fd("Error, wrong input !", 2);
	ft_putendl_fd("--------------------------------------------------", 2);
	ft_putendl_fd("Guide to usage:", 2);
	ft_putendl_fd("./fractol [option1] | [option2] ", 2);
	ft_putendl_fd("option1: ./fractol mandelbrot", 2);
	ft_putendl_fd("option2: ./fractol julia [parameter] [parameter]", 2);
	free(fractol);
	exit(EXIT_FAILURE);
}
	// system("leaks fractol");
