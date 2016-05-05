/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpressen <mpressen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/20 17:34:07 by mpressen          #+#    #+#             */
/*   Updated: 2016/05/05 18:38:38 by mpressen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static int		expose_hook(t_fractolparam *param)
{
	mlx_destroy_image(param->mlx, param->img);
	mlx_clear_window(param->mlx, param->win);
	draw_pic(&param);
	return (0);
}

int				key_hook(int keycode, t_fractolparam *param)
{
	if (keycode == 53 || keycode == 12)
		exit(EXIT_SUCCESS);
	else if (keycode == 69)
	{
		ft_putnbr(param->iteration_max);
		ft_putendl("<== iteration max");
		param->iteration_max += 1;
	}
	else if (keycode == 78 && param->iteration_max > 1)
	{
		ft_putnbr(param->iteration_max);
		ft_putendl("<== iteration max");
		param->iteration_max -= 1;
	}
	else if (keycode == 123)
		param->movex-= 50; 
	else if (keycode == 124)
		param->movex+= 50;
	else if (keycode == 125)
		param->movey+= 50;
	else if (keycode == 126)
		param->movey-= 50;
	expose_hook(param);
	return (0);
}

int				julia_hook(int x, int y, t_fractolparam *param)
{
	if (x <= 270 && y <= 240)
	{ 
		param->mousex = (double)x;
		param->mousey = (double)y;
	}
	expose_hook(param);
	return (0);
}

int				mouse_hook(int button, int x, int y, t_fractolparam *param)
{
	ft_putnbr(button);
	if (button == 1)
	{
		ft_putnbr(x);
		ft_putstr("x-y");
		ft_putnbr(y);
	}
	if (button == 7)
	{
		param->zoom += 1;
	}
	if (button == 5)
	{

		param->zoom -= 1;
	}
	expose_hook(param);
	return (0);
}
