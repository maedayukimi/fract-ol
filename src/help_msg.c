/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   help_msg.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mawako <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/25 15:23:53 by mawako            #+#    #+#             */
/*   Updated: 2025/01/27 20:18:58 by mawako           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	help_msg(t_fractol *f)
{
	ft_putendl_fd("\tThis is Fract'ol 42 project", 1);
	ft_putendl_fd("\tMandelbrot or Julia", 1);
	ft_putendl_fd("\tFractals' colors can be changed", 1);
	ft_putendl_fd("by putting color code after commands", 1);
	ft_putendl_fd("\tEx: ./fractol Julia -0.70176 -0.3842", 1);
	ft_putendl_fd("\tEx: ./fractol Julia -0.835 -0.2321 000000", 1);
	ft_putendl_fd("\tWASD or arrow keys to move", 1);
	ft_putendl_fd("\t+/- or scroll wheel to zoom", 1);
	ft_putendl_fd("\tSpace to change colors", 1);
	clean_exit(EXIT_FAILURE, f);
}
