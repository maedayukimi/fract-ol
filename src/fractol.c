/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mawako <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 17:10:03 by mawako            #+#    #+#             */
/*   Updated: 2025/01/26 17:12:09 by mawako           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	get_set(t_fractol *f, char **av)
{
	char	initial;

	initial = ft_tolower(av[1][0]);
	if (initial == 'm')
		f->set = MANDELBROT;
	else if (initial == 'j')
		f->set = JULIA;
	else
		help_msg(f);
	printf("f->set: %d\n", f->set);
}

static void	get_julia_starting_values(t_fractol *f, int ac, char **av)
{
	if (f->set != JULIA || ac == 2)
	{
		f->kr = -0.766667;
		f->ki = -0.090000;
		return ;
	}
	if (ac == 3)
		help_msg(f);
	if (!ft_strchr(av[2], '.'))
		help_msg(f);
	if (!ft_strchr(av[3], '.'))
		help_msg(f);
	f->kr = ft_atof(av[2]);
	f->ki = ft_atof(av[3]);
	if (f->kr > 2.0 || f->kr < -2.0)
		help_msg(f);
	if (f->ki >= 2.0 || f->ki <= -2.0)
		help_msg(f);
}

static void	handle_args(t_fractol *f, int ac, char **av)
{
	get_set(f, av);
	if (f->set != JULIA && ac > 3)
		help_msg(f);
	else if (f->set == JULIA && ac > 5)
		help_msg(f);
	get_julia_starting_values(f, ac, av);
	get_color(f, ac, av);
}

int	main(int ac, char **av)
{
	t_fractol	f;

	clean_init(&f);
	if (ac < 2)
		help_msg(&f);
	handle_args(&f, ac, av);
	init(&f);
	render(&f);
	print_controls();
	mlx_hook(f.win, EVENT_CLOSE_BTN, 0, end_fractol, &f);
	mlx_key_hook(f.win, key_event, &f);
	mlx_mouse_hook(f.win, mouse_event, &f);
	mlx_loop(f.mlx);
}
