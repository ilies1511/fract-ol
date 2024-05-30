/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iziane <iziane@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/30 21:25:39 by iziane            #+#    #+#             */
/*   Updated: 2024/05/30 23:55:15 by iziane           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void	fractol_init(t_params *fractol)
{

}

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
	exit(1);
}

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

int	main(int argc, char **argv)
{
	t_params	*fractol;

	fractol = (t_params *)malloc(sizeof(t_params));
	parser(argc, argv, fractol);
	printf("Option: %u\n", fractol->option);
	fractol_init(fractol);
	return (0);
}
