/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mawako <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 13:48:12 by mawako            #+#    #+#             */
/*   Updated: 2025/02/01 16:05:53 by mawako           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	color_shift(t_fractol *f)
{
	static int	origin_color = -1;

	if (origin_color == -1)
		origin_color = f->color;
	f->color_pattern = (f->color_pattern + 1) % 9;
	reinit_img(f);
	if (f->color_pattern == 0)
	{
		f->color = origin_color;
		if (f->color == 0x000000)
			f->color = 0x333333;
	}
	else
		f->color = base_colors(f->color_pattern);
	draw_color(f, f->color);
	render(f);
}

int	base_colors(int color_pattern)
{
	int	new_color;

	new_color = 0x4b0082;
	if (color_pattern == 1)
		new_color = 0xFF4500;
	else if (color_pattern == 2)
		new_color = 0xB22222;
	else if (color_pattern == 3)
		new_color = 0xDAA520;
	else if (color_pattern == 4)
		new_color = 0xFFBF00;
	else if (color_pattern == 5)
		new_color = 0x50C878;
	else if (color_pattern == 6)
		new_color = 0x228B22;
	else if (color_pattern == 7)
		new_color = 0x87CEEB;
	else if (color_pattern == 8)
		new_color = 0x1E3A8A;
	return (new_color);
}
