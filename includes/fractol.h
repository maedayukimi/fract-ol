/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mawako <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 16:05:18 by mawako            #+#    #+#             */
/*   Updated: 2025/02/05 15:37:53 by mawako           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "libft.h"
# include "mlx.h"
# include "keys.h"
# include <stdio.h>
# include <math.h>

# define WIDTH 900
# define HEIGHT 900
# define MAX_ITER 60

# define MANDELBROT 1
# define JULIA 2

typedef struct s_fractol
{
	void	*mlx;
	void	*win;
	void	*img;
	char	*buf;
	int		set;
	double	min_r;
	double	max_r;
	double	min_i;
	double	max_i;
	double	kr;
	double	ki;
	double	sx;
	double	rx;
	double	fx;
	int		*palette;
	int		color_pattern;
	int		color;
}	t_fractol;

int		mandelbrot(double cr, double ci);
int		julia(t_fractol *f, double zr, double zi);
void	render(t_fractol *f);
void	color_shift(t_fractol *f);
void	draw_color(t_fractol *f, int color);
int		base_colors(int color_pattern);
int		key_event(int keycode, t_fractol *mlx);
int		mouse_event(int keycode, int x, int y, t_fractol *mlx);
void	init(t_fractol *f);
void	reinit_img(t_fractol *f);
void	mlx_initialize(t_fractol *f);
void	get_color(t_fractol *f, int ac, char **av);
double	ft_atof(char *str);
int		end_fractol(t_fractol *mlx);
void	clean_exit(int error_code, t_fractol *f);
int		msg(char *str1, char *str2, int errno);
void	help_msg(t_fractol *f);

#endif
