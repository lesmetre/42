/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpressen <mpressen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/12 01:10:10 by mpressen          #+#    #+#             */
/*   Updated: 2016/06/03 13:24:45 by mpressen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void		init_param(t_fractolparam **addr_p, char *fractal)
{
	t_fractolparam	*p;

	if (!(p = (t_fractolparam*)malloc(sizeof(*p))))
		exit(1);
	p->fractal = fractal;
	recon_fractal(p);
	p->mlx = mlx_init();
	p->zoom = 100;
	p->x1 = -2.4;
	p->x2 = 2.4;
	p->y1 = -2.4;
	p->y2 = 2.4;
	p->width = p->zoom * (p->x2 - p->x1);
	p->height = p->zoom * (p->y2 - p->y1);
	p->pixmax = p->width * p->height;
	p->imax = 20;
	p->mousex = 0;
	p->mousey = 0;
	p->color = 1;
	p->win = mlx_new_window(p->mlx, p->width + 200, p->height, "FRACTOL");
	*addr_p = p;
}

static void		ft_fractal_list2(void)
{
	ft_putstr("\033[1;32m|\033[0m 7) mpressen			    ");
	ft_putendl("			\033[1;32m|\033[0m");
	ft_putstr("\033[1;32m|\033[0m 8) julia				");
	ft_putendl("		\033[1;32m|\033[0m");
	ft_putstr("\033[1;32m|\033[0m 9) sierpinski_triangle		");
	ft_putendl("		\033[1;32m|\033[0m");
	ft_putstr("\033[1;32m|\033[0m 10) sierpinski_carpet			");
	ft_putendl("		\033[1;32m|\033[0m");
	ft_putstr("\033[1;32m---------------------------\033[0m");
	ft_putendl("\033[1;32m------------------------------\033[0m");
}

static int		ft_fractal_list(void)
{
	ft_putstr("\033[1;32m---------------------\033[0m");
	ft_putstr("\033[1;31m FRACTALS LIST \033[0m");
	ft_putendl("\033[1;32m---------------------\033[0m");
	ft_putstr("\033[1;32m|\033[0m 1) mandelbrot			");
	ft_putendl("			\033[1;32m|\033[0m");
	ft_putstr("\033[1;32m|\033[0m 2) mandelbar			");
	ft_putendl("			\033[1;32m|\033[0m");
	ft_putstr("\033[1;32m|\033[0m 3) multibrot			");
	ft_putendl("			\033[1;32m|\033[0m");
	ft_putstr("\033[1;32m|\033[0m 4) multibar			");
	ft_putendl("			\033[1;32m|\033[0m");
	ft_putstr("\033[1;32m|\033[0m 5) burning_ship		");
	ft_putendl("			\033[1;32m|\033[0m");
	ft_putstr("\033[1;32m|\033[0m 6) logbrot			    ");
	ft_putendl("			\033[1;32m|\033[0m");
	ft_fractal_list2();
	return (1);
}

int				exit_hook(void)
{
	exit(EXIT_SUCCESS);
	return (0);
}

int				main(int ac, char **av)
{
	t_fractolparam			*p;

	p = NULL;
	if (ac < 2 || (ft_strcmp(av[1], "julia") && ft_strcmp(av[1], "mandelbrot")
			&& ft_strcmp(av[1], "burning_ship") && ft_strcmp(av[1], "multibrot")
			&& ft_strcmp(av[1], "mandelbar") && ft_strcmp(av[1], "multibar")
			&& ft_strcmp(av[1], "logbrot") && ft_strcmp(av[1], "mpressen")
			&& ft_strcmp(av[1], "sierpinski_triangle") && ft_strcmp(av[1], "1")
			&& ft_strcmp(av[1], "sierpinski_carpet") && ft_strcmp(av[1], "2")
			&& ft_strcmp(av[1], "3") && ft_strcmp(av[1], "5")
			&& ft_strcmp(av[1], "4") && ft_strcmp(av[1], "6")
			&& ft_strcmp(av[1], "7") && ft_strcmp(av[1], "8")
			&& ft_strcmp(av[1], "10") && ft_strcmp(av[1], "9")))
		return (ft_fractal_list());
	init_param(&p, av[1]);
	draw_pic(&p);
	mlx_hook(p->win, 2, 3, key_hook, p);
	mlx_mouse_hook(p->win, mouse_hook, p);
	mlx_hook(p->win, 6, 1L << 6, julia_hook, p);
	mlx_hook(p->win, 17, 1L << 17, exit_hook, p);
	mlx_loop(p->mlx);
	return (0);
}
