/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   help_msg.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mawako <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/25 15:23:53 by mawako            #+#    #+#             */
/*   Updated: 2025/01/26 19:18:31 by mawako           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	help_msg(t_fractol *f)
{
	ft_putendl_fd("\tMandelbrot or Julia", 1);
	ft_putendl_fd("\tWASD or arrow keys to move", 1);
	ft_putendl_fd("\t+/- or scroll wheel to zoom", 1);
	clean_exit(EXIT_FAILURE, f);
}
