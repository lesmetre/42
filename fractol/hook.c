/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpressen <mpressen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/20 17:34:07 by mpressen          #+#    #+#             */
/*   Updated: 2016/05/26 19:08:44 by mpressen         ###   ########.fr       */
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
		param->iteration_max += 1;
	else if (keycode == 78 && param->iteration_max > 1)
		param->iteration_max -= 1;
	if (keycode == 49)
		param->block = 1;
	if (keycode == 36)
		param->block = 0;
	else if (keycode == 123)
		param->movex -= 50; 
	else if (keycode == 124)
		param->movex += 50;
	else if (keycode == 125)
		param->movey += 50;
	else if (keycode == 126)
		param->movey -= 50;
	expose_hook(param);
	return (0);
}

int				julia_hook(int x, int y, t_fractolparam *param)
{
	if (!param->block)
	{
		param->mousex = (double)x;
		param->mousey = (double)y;
		expose_hook(param);
	}
	return (0);
}

int				mouse_hook(int button, int x, int y, t_fractolparam *param)
{
	double posx;
	double posy;

	if (button == 1 || button == 5 || button == 4)
	{
		posx = (double)x / param->zoom + param->x1;
		posy = (double)y / param->zoom + param->y1;
		if(button == 5 || button == 1)
		{
			param->zoom *= 1.1;
			param->iteration_max += 1;
		}
		else
		{
			param->zoom *= 0.9;
			param->iteration_max -= 1;
		}
		param->x1 = posx - param->width / 2 / param->zoom;
		param->y1 = posy - param->height / 2 / param->zoom;
		expose_hook(param);
	}
	return (0);
}
