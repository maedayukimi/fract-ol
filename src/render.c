/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mawako <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 18:40:12 by mawako            #+#    #+#             */
/*   Updated: 2025/01/29 19:41:55 by mawako           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	draw(t_fractol *f, int x, int y, int color)
{
	int	position;

	position = x * 4 + y * WIDTH * 4;
	f->buf[position] = (color >> 0) & 0xFF;
	f->buf[position + 1] = (color >> 8) & 0xFF;
	f->buf[position + 2] = (color >> 16) & 0xFF;
	f->buf[position + 3] = (color >> 24) & 0xFF;
}

static int	calculate_fractal(t_fractol *f, double pr, double pi)
{
	int	nb_iter;

	if (f->set == MANDELBROT)
		nb_iter = mandelbrot(pr, pi);
	else if (f->set == JULIA)
		nb_iter = julia(f, pr, pi);
	return (nb_iter);
}

void	render(t_fractol *f)
{
	int		x;
	int		y;
	double	pr;
	double	pi;
	int		nb_iter;

	mlx_clear_window(f->mlx, f->win);
	y = 0;
	while (y < HEIGHT)
	{
		x = 0;
		while (x < WIDTH)
		{
			pr = f->min_r + (double)x * (f->max_r - f->min_r) / WIDTH;
			pi = f->max_i + (double)y * (f->min_i - f->max_i) / HEIGHT;
			nb_iter = calculate_fractal(f, pr, pi);
			draw(f, x, y, f->palette[nb_iter]);
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(f->mlx, f->win, f->img, 0, 0);
}
