/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpressen <mpressen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/12 01:10:10 by mpressen          #+#    #+#             */
/*   Updated: 2016/05/27 18:40:22 by mpressen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void		init_param(t_fractolparam **addr_param, char *fractal)
{
    t_fractolparam  *param;

    if (!(param = (t_fractolparam*)malloc(sizeof(*param))))
        exit(1);
    param->fractal = fractal;
    param->mlx = mlx_init();
	param->zoom = 100;
	param->x1 = -2.4;
	param->x2 = 2.4;
	param->y1 = -2.4;
	param->y2 = 2.4;
	param->width = param->zoom * (param->x2 - param->x1);
	param->height = param->zoom * (param->y2 - param->y1);
	param->pixmax = param->width * param->height;
	param->iteration_max = 20;
	param->mousex = 0;
	param->mousey = 0;
	param->color = 1;
    param->win = mlx_new_window(param->mlx, param->width, param->height, "FRACTOL");
    *addr_param = param;
}

static int		ft_fractal_list(void)
{
	ft_putstr("\033[1;32m---------------------\033[0m");
	ft_putstr("\033[1;31m FRACTALS LIST \033[0m");
	ft_putendl("\033[1;32m---------------------\033[0m");
	ft_putstr("\033[1;32m|\033[0m 1) Mandelbrot			");
	ft_putendl("			\033[1;32m|\033[0m");
	ft_putstr("\033[1;32m|\033[0m 2) Mandelbar			");
	ft_putendl("			\033[1;32m|\033[0m");
	ft_putstr("\033[1;32m|\033[0m 3) Multibrot			");
	ft_putendl("			\033[1;32m|\033[0m");
	ft_putstr("\033[1;32m|\033[0m 4) Multibar			");
	ft_putendl("			\033[1;32m|\033[0m");
	ft_putstr("\033[1;32m|\033[0m 5) Burning_ship		");
	ft_putendl("			\033[1;32m|\033[0m");
	ft_putstr("\033[1;32m|\033[0m 6) Logbrot			    ");
	ft_putendl("			\033[1;32m|\033[0m");
	ft_putstr("\033[1;32m|\033[0m 7) Mpressen			    ");
	ft_putendl("			\033[1;32m|\033[0m");
	ft_putstr("\033[1;32m|\033[0m 8) Julia				");
	ft_putendl("		\033[1;32m|\033[0m");
	ft_putstr("\033[1;32m|\033[0m 9) Sierpinski_triangle		");
	ft_putendl("		\033[1;32m|\033[0m");
	ft_putstr("\033[1;32m|\033[0m 10) Sierpinski_carpet			");
	ft_putendl("		\033[1;32m|\033[0m");
	ft_putstr("\033[1;32m---------------------------\033[0m");
	ft_putendl("\033[1;32m------------------------------\033[0m");
	return (1);
}

int				exit_hook(void)
{
	exit(EXIT_SUCCESS);
	return (0);
}

int				main(int ac, char **av)
{
	t_fractolparam			*param;

	param = NULL;
	if (ac < 2 || (ft_strcmp(av[1], "Julia") && ft_strcmp(av[1], "Mandelbrot")
	&& ft_strcmp(av[1], "Burning_ship") && ft_strcmp(av[1], "Multibrot")
	&& ft_strcmp(av[1], "Mandelbar") && ft_strcmp(av[1], "Multibar")
	&& ft_strcmp(av[1], "Logbrot") && ft_strcmp(av[1], "Mpressen")
	&& ft_strcmp(av[1], "Sierpinski_triangle")
	&& ft_strcmp(av[1], "Sierpinski_carpet")))
		return (ft_fractal_list());
	init_param(&param, av[1]);
	draw_pic(&param);
	mlx_hook(param->win, 2, 3, key_hook, param);
	mlx_mouse_hook(param->win, mouse_hook, param);
	mlx_hook(param->win, 6, 1L<<6, julia_hook, param);
	mlx_hook(param->win, 17, 1L<<17, exit_hook, param);
	mlx_loop(param->mlx);
	return (0);
}	
