/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_case.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iziane <iziane@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/02 00:27:15 by iziane            #+#    #+#             */
/*   Updated: 2024/06/02 00:27:30 by iziane           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

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
