/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_legend.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpressen <mpressen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/02 12:04:42 by mpressen          #+#    #+#             */
/*   Updated: 2016/06/03 13:19:34 by mpressen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int		expose_hook(t_fractolparam *p)
{
	mlx_clear_window(p->mlx, p->win);
	draw_pic(&p);
	return (0);
}

int		julia_hook(int x, int y, t_fractolparam *p)
{
	if (!p->block)
	{
		p->mousex = (double)x;
		p->mousey = (double)y;
		expose_hook(p);
	}
	return (0);
}

void	draw_square(t_fractolparam *p)
{
	int x;
	int y;

	y = 1;
	x = 1;
	while (++y < p->height - 3)
	{
		mlx_pixel_put(p->mlx, p->win, p->width + 2, y, 0x00ff00);
		mlx_pixel_put(p->mlx, p->win, p->width + 197, y, 0x00ff00);
	}
	while (++x < 197)
	{
		mlx_pixel_put(p->mlx, p->win, x + p->width, 2, 0x00ff00);
		mlx_pixel_put(p->mlx, p->win, x + p->width, p->height - 3, 0x00ff00);
	}
}

void	draw_legend2(t_fractolparam *p)
{
	mlx_string_put(p->mlx, p->win, p->width + 10, 291, 0x0000ff, "zoom: ");
	if (p->zoom < 2147483648)
		mlx_string_put(p->mlx, p->win, p->width + 85, 291, 0x00ff00,
						ft_itoa_base(p->zoom, 10));
	else
		mlx_string_put(p->mlx, p->win, p->width + 78, 291, 0xff0000,
						"WooooooW !!!");
	mlx_string_put(p->mlx, p->win, p->width + 10, 311, 0x0000ff, "iteration:");
	mlx_string_put(p->mlx, p->win, p->width + 125, 311, 0x00ff00,
					ft_itoa_base(p->imax, 10));
	mlx_string_put(p->mlx, p->win, p->width + 10, 331, 0x0000ff, "freeze:");
	if (!p->block)
		mlx_string_put(p->mlx, p->win, p->width + 90, 331, 0x00ff00, "OFF");
	else
		mlx_string_put(p->mlx, p->win, p->width + 90, 331, 0xff0000, "ON");
	if (p->mandel)
		draw_minimandel(p, -1, -1, -1);
}

void	draw_legend(t_fractolparam *p)
{
	draw_square(p);
	mlx_string_put(p->mlx, p->win, p->width + (200 - ft_strlen(p->fractal)
					* 10) / 2, 21, 0x00ffff, p->fractal);
	mlx_string_put(p->mlx, p->win, p->width + 10, 61, 0xff00ff,
					"move: arrow keys");
	mlx_string_put(p->mlx, p->win, p->width + 10, 81, 0xff00ff, "zoom: scroll");
	mlx_string_put(p->mlx, p->win, p->width + 10, 141, 0xff00ff,
					"center view: clic");
	mlx_string_put(p->mlx, p->win, p->width + 10, 101, 0xff00ff,
					"color set: 1-9");
	mlx_string_put(p->mlx, p->win, p->width + 10, 121, 0xff00ff,
					"iteration: + / -");
	mlx_string_put(p->mlx, p->win, p->width + 10, 161, 0xff00ff,
					"(un)freeze: space");
	mlx_string_put(p->mlx, p->win, p->width + 10, 181, 0xff00ff,
					"exit: echap / q");
	mlx_string_put(p->mlx, p->win, p->width + 10, 201, 0xff00ff,
					"reset: return");
	mlx_string_put(p->mlx, p->win, p->width + 10, 221, 0xff00ff,
					"mandelbrot: M");
	mlx_string_put(p->mlx, p->win, p->width + 10, 241, 0xff00ff,
					"fractal: < >");
	draw_legend2(p);
}
