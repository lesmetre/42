/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpressen <mpressen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/12 01:10:10 by mpressen          #+#    #+#             */
/*   Updated: 2016/05/04 17:11:22 by mpressen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void		init_param(t_fractolparam **addr_param, char *fractal)
{
    t_fractolparam  *param;

    if (!(param = (t_fractolparam*)malloc(sizeof(*param))))
        exit(1);
    param->width = 2560;
    param->height =1395;
    param->fractal = fractal;
    param->mlx = mlx_init();
    param->win = mlx_new_window(param->mlx, param->width, param->height, "FRACTOL");
    if (!ft_strcmp(param->fractal, "Mandelbrot"))
        init_Mandelbrot(&param);
    else if (!ft_strcmp(param->fractal, "Mandelbar"))
        init_Mandelbar(&param);
    else if (!ft_strcmp(param->fractal, "Multibrot"))
        init_Multibrot(&param);
    else if (!ft_strcmp(param->fractal, "Multibar"))
        init_Multibar(&param);
    else if (!ft_strcmp(param->fractal, "Burning_ship"))
        init_Burning_ship(&param);
    else if (!ft_strcmp(param->fractal, "Julia"))
        init_Julia(&param);
    else if (!ft_strcmp(param->fractal, "Sierpinski_triangle"))
        init_Sierpinski_triangle(&param);
    else if (!ft_strcmp(param->fractal, "Sierpinski_carpet"))
        init_Sierpinski_carpet(&param);
	param->mousex = 0;
	param->mousey = 0;
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
	ft_putstr("\033[1;32m|\033[0m 6) Julia				");
	ft_putendl("		\033[1;32m|\033[0m");
	ft_putstr("\033[1;32m|\033[0m 7) Sierpinski_carpet	");
	ft_putendl("				\033[1;32m|\033[0m");
	ft_putstr("\033[1;32m|\033[0m 8) Sierpinski_triangle	");
	ft_putendl("			\033[1;32m|\033[0m");
	ft_putstr("\033[1;32m---------------------------\033[0m");
	ft_putendl("\033[1;32m------------------------------\033[0m");
	return (1);
}

int				main(int ac, char **av)
{
	t_fractolparam			*param;

	param = NULL;
	if (ac < 2 || (ft_strcmp(av[1], "Julia") && ft_strcmp(av[1], "Mandelbrot")
	&& ft_strcmp(av[1], "Burning_ship") && ft_strcmp(av[1], "Multibrot")
	&& ft_strcmp(av[1], "Mandelbar") && ft_strcmp(av[1], "Multibar")
	&& ft_strcmp(av[1], "Sierpinski_triangle")
	&& ft_strcmp(av[1], "Sierpinski_carpet")))
		return (ft_fractal_list());
	init_param(&param, av[1]);
	draw_pic(&param);
	mlx_hook(param->win, 2, 3, key_hook, param);
	mlx_hook(param->win, 6, 1L<<6, julia_hook, param);
	mlx_loop(param->mlx);
	return (0);
}
//	mlx_mouse_hook(param->win, mouse_hook, param);
//	mlx_key_hook(param->win, key_hook, param);
//	mlx_expose_hook(param->win, expose2_hook, param);
//	mlx_loop_hook(param->mlx, loop_hook, param);	
//	mlx_hook(param->win, 6, 1L << 6, mouse_hook, param);
	
