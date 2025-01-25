/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   help_msg.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mawako <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/25 15:23:53 by mawako            #+#    #+#             */
/*   Updated: 2025/01/25 15:36:50 by mawako           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	print_fractal_options(void)
{
	ft_putendl_fd("\tM - Mandelbrot", 1);
	ft_putendl_fd("\tJ - Julia", 1);
}

void	print_color_options(void)
{
	ft_putendl_fd("\tWhite:\tFFFFFF\t\tBlack:\t000000", 1);
	ft_putendl_fd("\tBlue:\t0000FF\t\tPurple:\t9933FF", 1);
	ft_putendl_fd("\tTurquoise: 00FF80\t", 1);
}

void	print_controls(void)
{
	ft_putendl_fd("WASD or arrow keys to move", 1);
	ft_putendl_fd("+/- or scroll wheel to zoom", 1);
}

void	help_msg(t_fractol *f)
{
	ft_putendl_fd("FRACT'OL", 1);
	print_fractal_options();
	print_color_options();
	clean_exit(EXIT_FAILURE, f);
}
