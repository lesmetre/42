/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpressen <mpressen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/12 01:10:10 by mpressen          #+#    #+#             */
/*   Updated: 2016/04/29 12:09:47 by mpressen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"


static void		init_param(t_fractolparam **addr_param, char *fractal)
{
	t_fractolparam	*param;

	if (!(param = (t_fractolparam*)malloc(sizeof(*param))))
		exit(1);
	param->fractal = fractal;
	param->mlx = mlx_init();
	param->zoom = 300;
	if (!ft_strcmp(param->fractal, "Mandelbraut"))
	{
		param->x1 = -2.1;
		param->x2 = 0.6;
		param->y1 = -1.2;
		param->y2 = 1.2;
		param->iteration_max = 50;
	}
	if (!ft_strcmp(param->fractal, "Multibrot"))
	{
		param->x1 = -2.1;
		param->x2 = 2.1;
		param->y1 = -2.1;
		param->y2 = 2.1;
		param->iteration_max = 50;
	}
	if (!ft_strcmp(param->fractal, "Burning_Ship"))
	{
		param->x1 = -2.1;
		param->x2 = 1.1;
		param->y1 = -1.9;
		param->y2 = 0.6;
		param->iteration_max = 100;
		
	}
	else if (!ft_strcmp(param->fractal, "Julia"))
	{
		param->x1 = -1;
		param->x2 = 1;
		param->y1 = -1.2;
		param->y2 = 1.2;
		param->iteration_max = 150;
	}
	param->image_x = (param->x2 - param->x1) * param->zoom;
	param->image_y = (param->y2 - param->y1) * param->zoom;
	param->win = mlx_new_window(param->mlx, param->image_x, param->image_y, "FRACTOL");
	param->img = mlx_new_image(param->mlx, param->image_x, param->image_y);
	param->pic = (unsigned int *)mlx_get_data_addr(param->img, &param->bpp, &param->sizeline, &param->endian);
	*addr_param = param;
	param->pixmax = param->image_x * param->image_y;
}

static int		ft_fractal_list(void)
{
	ft_putendl("liste des fractales");
	return (1);
}

int				main(int ac, char **av)
{
	t_fractolparam			*param;

	param = NULL;
	if (ac < 2 || (ft_strcmp(av[1], "Julia") && ft_strcmp(av[1], "Mandelbraut")
				   && ft_strcmp(av[1], "Burning_Ship") && ft_strcmp(av[1], "Multibrot")))
		return (ft_fractal_list());
	init_param(&param, av[1]);
	draw_pic(param);
	mlx_key_hook(param->win, key_hook, param);
	mlx_hook(param->win, 2, 3, key_hook, param);
	mlx_loop(param->mlx);
	return (0);
}
