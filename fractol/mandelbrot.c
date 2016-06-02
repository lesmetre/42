/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpressen <mpressen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/03 17:17:06 by mpressen          #+#    #+#             */
/*   Updated: 2016/06/02 18:30:50 by mpressen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	draw_minimandel(t_fractolparam *p, int x, int y, int i)
{
	while (++x < 135)
	{
		p->c_r = (double)x / 50 - 2.1;
		y = -1;
		while (++y < 120)
		{
			p->c_i = (double)y / 50 - 1.2;
			p->z_r = 0;
			p->z_i = 0;
			i = -1;
			while (p->z_r * p->z_r + p->z_i * p->z_i < 4 && ++i < 51)
			{
				p->tmp = p->z_r;
				p->z_r = p->z_r * p->z_r - p->z_i * p->z_i + p->c_r;
				p->z_i = 2 * p->z_i * p->tmp + p->c_i;
			}
			mlx_pixel_put(p->mlx, p->win, x, y, i * 5);
		}
		mlx_pixel_put(p->mlx, p->win, x, y, 0xffffff);
	}
	y = -1;
	while (++y < 120)
		mlx_pixel_put(p->mlx, p->win, x, y, 0xffffff);
}

void	draw_mandelbrot(t_fractolparam *p)
{
	int y;
	int x;
	int i;

	y = -1;
	while (++y <= p->height)
	{
		p->c_i = (y - p->movey) / p->zoom + p->y1;
		x = -1;
		while (++x <= p->width)
		{
			p->c_r = (x - p->movex) / p->zoom + p->x1;
			p->z_r = 0;
			p->z_i = 0;
			i = -1;
			while (p->z_r * p->z_r + p->z_i * p->z_i < 4 && ++i < p->imax)
			{
				p->tmp = p->z_r;
				p->z_r = p->z_r * p->z_r - p->z_i * p->z_i + p->c_r;
				p->z_i = 2 * p->z_i * p->tmp + p->c_i;
			}
			choose_color(x, y, p, i);
		}
	}
}
