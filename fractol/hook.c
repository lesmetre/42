/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpressen <mpressen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/20 17:34:07 by mpressen          #+#    #+#             */
/*   Updated: 2016/05/05 12:00:46 by mpressen         ###   ########.fr       */
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
		param->zoom += 10;
	else if (keycode == 78)
		param->zoom -= 10;
	expose_hook(param);
	return (0);
}

int				julia_hook(int x, int y, t_fractolparam *param)
{
	param->mousex = (double)x;
	param->mousey = (double)y;
	expose_hook(param);
	return (0);
}

int				mouse_hook(int button, int x, int y, t_fractolparam *param)
{
	param = NULL;
	if (button == 1)
	{
		ft_putnbr(x);
		ft_putendl(" <== x");
		ft_putnbr(y);
		ft_putendl(" <== y");
	}
	return (0);
}
