/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_gradation.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mawako <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 19:45:02 by mawako            #+#    #+#             */
/*   Updated: 2025/02/03 17:52:38 by mawako           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static int	set_gradation(int startcolor, int endcolor, double fraction)
{
	int	start_rgb[3];
	int	end_rgb[3];

	start_rgb[0] = ((startcolor >> 16) & 0xFF);
	start_rgb[1] = ((startcolor >> 8) & 0xFF);
	start_rgb[2] = ((startcolor >> 0) & 0xFF);
	end_rgb[0] = ((endcolor >> 16) & 0xFF);
	end_rgb[1] = ((endcolor >> 8) & 0xFF);
	end_rgb[2] = ((endcolor >> 0) & 0xFF);
	start_rgb[0] = (int)(start_rgb[0] + (end_rgb[0] - start_rgb[0]) * fraction);
	start_rgb[1] = (int)(start_rgb[1] + (end_rgb[1] - start_rgb[1]) * fraction);
	start_rgb[2] = (int)(start_rgb[2] + (end_rgb[2] - start_rgb[2]) * fraction);
	return (0xFF << 24 | start_rgb[0] << 16 | start_rgb[1] << 8 | start_rgb[2]);
}

void	draw_color(t_fractol *f, int color)
{
	int		i;
	int		j;
	double	fraction;
	int		color1;
	int		color2;

	color1 = 0x000000;
	color2 = color;
	i = 0;
	while (i < MAX_ITER)
	{
		j = 0;
		while (j < MAX_ITER / 2)
		{
			fraction = (double)j / (MAX_ITER / 2);
			f->palette[i + j++] = set_gradation(color1, color2, fraction);
		}
		color1 = color2;
		color2 = 0xFFFFFF;
		i += j;
	}
	f->palette[MAX_ITER - 1] = 0;
}
