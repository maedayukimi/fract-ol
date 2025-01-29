/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_special.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mawako <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 19:57:06 by mawako            #+#    #+#             */
/*   Updated: 2025/01/28 20:16:13 by mawako           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	pattern_6(t_fractol *f, int color)
{
	int	i;
	int	r;
	int	g;
	int	b;

	r = (color >> 16) & 0xFF;
	g = (color >> 8) & 0xFF;
	b = (color >> 0) & 0xFF;
	i = 0;
	while (i < MAX_ITER)
	{
		f->palette[i] = 0;
		r += i % 0xFF;
		g += i % 0xFF;
		b += i % 0xFF;
		f->palette[i++] = 0xFF << 24 | r << 16 | g << 8 | b;
	}
	f->palette[MAX_ITER - 1] = 0;
}

void	pattern_5(t_fractol *f, int color)
{
	int	i;
	int	r;
	int	g;
	int	b;

	r = (color >> 16) & 0xFF;
	g = (color >> 8) & 0xFF;
	b = (color >> 0) & 0xFF;
	i = 0;
	while (i < MAX_ITER)
	{
		f->palette[i] = 0;
		if (r != 0xFF)
			r += i % 0xFF;
		if (g != 0xFF)
			g += i % 0xFF;
		if (b != 0xFF)
			b += i % 0xFF;
		f->palette[i++] = 0xFF << 24 | r << 16 | g << 8 | b;
	}
	f->palette[MAX_ITER - 1] = 0;
}

void	pattern_7(t_fractol *f, int color)
{
	int	i;
	int	rgb[3];

	rgb[0] = (color >> 16) & 0xFF;
	rgb[1] = (color >> 8) & 0xFF;
	rgb[2] = (color >> 0) & 0xFF;
	i = 0;
	while (rgb[0] < 0x33 || rgb[1] < 0x33 || rgb[2] < 0x33)
	{
		if (rgb[0] != 0xFF)
			rgb[0]++;
		if (rgb[1] != 0xFF)
			rgb[1]++;
		if (rgb[2] != 0xFF)
			rgb[2]++;
	}
	while (i < MAX_ITER)
	{
		f->palette[i] = 0;
		rgb[0] -= i % 0xFF;
		rgb[1] -= i % 0xFF;
		rgb[2] -= i & 0xFF;
		f->palette[i++] = 0xFF << 24 | rgb[0] << 16 | rgb[1] << 8 | rgb[2];
	}
	f->palette[MAX_ITER - 1] = 0;
}
