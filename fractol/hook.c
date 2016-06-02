/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpressen <mpressen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/20 17:34:07 by mpressen          #+#    #+#             */
/*   Updated: 2016/06/02 16:38:56 by mpressen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static int		expose_hook(t_fractolparam *p)
{
    mlx_destroy_image(p->mlx, p->img);
    mlx_clear_window(p->mlx, p->win);
    draw_pic(&p);
    return (0);
}

static void		set_colors(int keycode, t_fractolparam *p)
{
	if (keycode == 83)
		p->color = 1;
	else if (keycode == 84)
		p->color = 2;
	else if (keycode == 85)
		p->color = 3;
	else if (keycode == 86)
		p->color = 4;
	else if (keycode == 87)
		p->color = 5;
	else if (keycode == 88)
		p->color = 6;
	else if (keycode == 89)
		p->color = 7;
	else if (keycode == 91)
		p->color = 8;
	else if (keycode == 92)
		p->color = 9;
}

static void		move(int keycode, t_fractolparam *p)
{
	if (keycode == 123)
		p->movex -= 50;
	else if (keycode == 124)
		p->movex += 50;
	else if (keycode == 125)
		p->movey += 50;
	else if (keycode == 126)
		p->movey -= 50;
}

static void		reset(t_fractolparam *p)
{
	p->imax = 20;
	p->block = 0;
	p->movex = 0;
	p->movey = 0;
	p->color = 1;
	p->x1 = -2.4;
	p->y1 = -2.4;
	p->zoom = 100;
}

int				key_hook(int keycode, t_fractolparam *p)
{
	if (keycode == 53 || keycode == 12)
		exit(EXIT_SUCCESS);
	else if (keycode == 69)
		p->imax += 1;
	else if (keycode == 78 && p->imax > 1)
		p->imax -= 1;
	else if (keycode == 49)
	{
		if (!p->block)
			p->block = 1;
		else
			p->block = 0;
	}
	else if (keycode > 122 && keycode < 127)
		move(keycode, p);
	else if (keycode >= 82 && keycode <= 92)
		set_colors(keycode, p);
	else if (keycode == 36)
		reset(p);
	expose_hook(p);
	return (0);
}

int				julia_hook(int x, int y, t_fractolparam *p)
{
	if (!p->block)
	{
		p->mousex = (double)x;
		p->mousey = (double)y;
		expose_hook(p);
	}
	return (0);
}

int				mouse_hook(int button, int x, int y, t_fractolparam *p)
{
	double posx;
	double posy;

	if (button == 5 || button == 4 || button == 1)
	{
		posx = ((double)x - p->movex) / p->zoom + p->x1;
		posy = ((double)y - p->movey) / p->zoom + p->y1;
		if (button == 1)
		{
			p->x1 = posx - (p->width / 2 - p->movex) / p->zoom;
			p->y1 = posy - (p->height / 2 - p->movey) / p->zoom;
		}
		else
		{
			if (button == 5)
			{
				p->zoom *= 1.1;
					p->imax += 1;
			}
			else if (button == 4)
			{
				p->zoom *= 0.9;
				if (p->imax > 1)
					p->imax -= 1;
			}
			p->x1 = posx - ((double)x - p->movex) / p->zoom;
			p->y1 = posy - ((double)y - p->movey) / p->zoom;
		}
		expose_hook(p);
	}
	return (0);
}
