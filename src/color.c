/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mawako <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 13:48:12 by mawako            #+#    #+#             */
/*   Updated: 2025/01/28 20:06:08 by mawako           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	color_shift_special(t_fractol *f)
{
	int	alt_color;

	if (f->color == 0xFFFFFF)
		alt_color = 0xCCCCCC;
	else
		alt_color = f->color;
	if (f->color_pattern == 5)
		pattern_5(f, alt_color);
	else if (f->color_pattern == 6)
		pattern_6(f, f->color);
	else if (f->color_pattern == 7)
		pattern_7(f, f->color);
	else if (f->color_pattern == 8)
		pattern_1(f, (int [8]){0xFF0000, 0xFF7F00, 0xFFFF00,
			0x00FF00, 0x0000FF, 0x4B0082, 0x9400D3, 0xFFFFFF}, 8);
}

static void	color_shift_striped(t_fractol *f)
{
	if (f->color_pattern == 2)
		pattern_2(f, f->color);
	else if (f->color_pattern == 3)
		pattern_3(f, f->color);
	else if (f->color_pattern == 4)
		pattern_4(f, f->color);
	else
		color_shift_special(f);
}

void	color_shift(t_fractol *f)
{
	int	alt_color;

	f->color_pattern = (f->color_pattern + 1) % 9;
	reinit_img(f);
	if (f->color == 0x000000)
		alt_color = 0x333333;
	else
		alt_color = f->color;
	if (f->color_pattern == 0)
		pattern_0(f, alt_color);
	else if (f->color_pattern == 1)
		pattern_1(f, (int [4]){0x000000, alt_color,
			get_percent_color(f->color, 50), 0xFFFFFF}, 4);
	else
		color_shift_striped(f);
}
