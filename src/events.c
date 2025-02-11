/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mawako <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 16:21:37 by mawako            #+#    #+#             */
/*   Updated: 2025/02/05 15:38:21 by mawako           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	zoom(t_fractol *f, double zoom)
{
	double	width_r;
	double	height_i;
	double	new_width;
	double	new_height;

	width_r = (f->min_r + f->max_r) / 2;
	height_i = (f->min_i + f->max_i) / 2;
	new_width = (f->max_r - f->min_r) * zoom / 2;
	new_height = (f->max_i - f->min_i) * zoom / 2;
	f->min_r = width_r - new_width;
	f->max_r = width_r + new_width;
	f->min_i = height_i - new_height;
	f->max_i = height_i + new_height;
}

static void	move(t_fractol *f, double distance, char direction)
{
	double	width_r;
	double	height_i;

	width_r = f->max_r - f->min_r;
	height_i = f->max_i - f->min_i;
	if (direction == 'R')
	{
		f->min_r += width_r * distance;
		f->max_r += width_r * distance;
	}
	else if (direction == 'L')
	{
		f->min_r -= width_r * distance;
		f->max_r -= width_r * distance;
	}
	else if (direction == 'D')
	{
		f->min_i -= height_i * distance;
		f->max_i -= height_i * distance;
	}
	else if (direction == 'U')
	{
		f->min_i += height_i * distance;
		f->max_i += height_i * distance;
	}
}

static int	key_event_extend(int keycode, t_fractol *mlx)
{
	if (keycode == KEY_ONE && mlx->set != MANDELBROT)
		mlx->set = MANDELBROT;
	else if (keycode == KEY_TWO && mlx->set != JULIA)
		mlx->set = JULIA;
	else
		return (1);
	render(mlx);
	return (0);
}

int	key_event(int keycode, t_fractol *mlx)
{
	if (keycode == KEY_ESC)
	{
		end_fractol(mlx);
		return (0);
	}
	else if (keycode == KEY_UP || keycode == KEY_W)
		move(mlx, 0.2, 'U');
	else if (keycode == KEY_DOWN || keycode == KEY_S)
		move(mlx, 0.2, 'D');
	else if (keycode == KEY_LEFT || keycode == KEY_A)
		move(mlx, 0.2, 'L');
	else if (keycode == KEY_RIGHT || keycode == KEY_D)
		move(mlx, 0.2, 'R');
	else if (keycode == KEY_SPACE)
		color_shift(mlx);
	else if (!key_event_extend(keycode, mlx))
		return (1);
	else
		return (1);
	render(mlx);
	return (0);
}

int	mouse_event(int keycode, int x, int y, t_fractol *mlx)
{
	if (keycode == MOUSE_WHEEL_UP)
	{
		zoom(mlx, 0.5);
		x -= WIDTH / 2;
		y -= HEIGHT / 2;
		if (x < 0)
			move(mlx, (double)x * -1 / WIDTH, 'L');
		else if (x > 0)
			move(mlx, (double)x / WIDTH, 'R');
		if (y < 0)
			move(mlx, (double)y / HEIGHT, 'D');
	}
	else if (keycode == MOUSE_WHEEL_DOWN)
		zoom(mlx, 2);
	else
		return (0);
	render(mlx);
	return (0);
}
