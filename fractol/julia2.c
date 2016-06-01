/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpressen <mpressen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/03 17:35:19 by mpressen          #+#    #+#             */
/*   Updated: 2016/06/01 17:01:16 by mpressen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void		draw_julia1bis(t_fractolparam *p, int x, int y)
{
	int i;

	p->c_i = p->mousey / 100 - 1.2;
	while (++x < p->width)
	{
		p->c_r = p->mousex / 100 - 2.1;
		p->z_r = x / p->zoom + p->x1;
		p->z_i = y / p->zoom + p->y1;
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

void		draw_julia2bis(t_fractolparam *p, int x, int y)
{
	int i;

	p->c_i2 = p->mousey / 100 - 1.2;
	x = -1;
	while (++x < p->width)
	{
		p->c_r2 = p->mousex / 100 - 2.1;
		p->z_r2 = x / p->zoom + p->x1;
		p->z_i2 = y / p->zoom + p->y1;
		i = -1;
		while (p->z_r2 * p->z_r2 + p->z_i2 * p->z_i2 < 4 && ++i < p->imax)
		{
			p->tmp2 = p->z_r2;
			p->z_r2 = p->z_r2 * p->z_r2 - p->z_i2 * p->z_i2 + p->c_r2;
			p->z_i2 = 2 * p->z_i2 * p->tmp2 + p->c_i2;
		}
		if (p->color == 9)
			draw_pixel(x, y, p, i - (log(log(sqrt(p->z_r2 * p->z_r2 +
			p->z_i2 * p->z_i2)))) / log(2) + (i - (log(log(sqrt(p->z_r2
			* p->z_r2 + p->z_i2 * p->z_i2)))) / log(2)) * 255 + (i -
			(log(log(sqrt(p->z_r2 * p->z_r2 + p->z_i2 * p->z_i2)))) /
			log(2)) * 255 * 255);
		else
			choose_color(x, y, p, i);
	}
}

void		draw_julia3bis(t_fractolparam *p, int x, int y)
{
	int i;

	i = -1;
	p->c_i3 = p->mousey / 100 - 1.2;
	while (++x < p->width)
	{
		p->c_r3 = p->mousex / 100 - 2.1;
		p->z_r3 = x / p->zoom + p->x1;
		p->z_i3 = y / p->zoom + p->y1;
		i = -1;
		while (p->z_r3 * p->z_r3 + p->z_i3 * p->z_i3 < 4 && ++i < p->imax)
		{
			p->tmp3 = p->z_r3;
			p->z_r3 = p->z_r3 * p->z_r3 - p->z_i3 * p->z_i3 + p->c_r3;
			p->z_i3 = 2 * p->z_i3 * p->tmp3 + p->c_i3;
		}
		if (p->color == 9)
			draw_pixel(x, y, p, i - (log(log(sqrt(p->z_r3 * p->z_r3 +
			p->z_i3 * p->z_i3)))) / log(2) + (i - (log(log(sqrt(p->z_r3
			* p->z_r3 + p->z_i3 * p->z_i3)))) / log(2)) * 255 + (i -
			(log(log(sqrt(p->z_r3 * p->z_r3 + p->z_i3 * p->z_i3)))) /
			log(2)) * 255 * 255);
		else
			choose_color(x, y, p, i);
	}
}

void		draw_julia4bis(t_fractolparam *p, int x, int y)
{
	int i;

	i = -1;
	p->c_i4 = p->mousey / 100 - 1.2;
	while (++x < p->width)
	{
		p->c_r4 = p->mousex / 100 - 2.1;
		p->z_r4 = x / p->zoom + p->x1;
		p->z_i4 = y / p->zoom + p->y1;
		i = -1;
		while (p->z_r4 * p->z_r4 + p->z_i4 * p->z_i4 < 4 && ++i < p->imax)
		{
			p->tmp4 = p->z_r4;
			p->z_r4 = p->z_r4 * p->z_r4 - p->z_i4 * p->z_i4 + p->c_r4;
			p->z_i4 = 2 * p->z_i4 * p->tmp4 + p->c_i4;
		}
		if (p->color == 9)
			draw_pixel(x, y, p, i - (log(log(sqrt(p->z_r4 * p->z_r4 +
			p->z_i4 * p->z_i4)))) / log(2) + (i - (log(log(sqrt(p->z_r4
			* p->z_r4 + p->z_i4 * p->z_i4)))) / log(2)) * 255 + (i -
			(log(log(sqrt(p->z_r4 * p->z_r4 + p->z_i4 * p->z_i4)))) /
			log(2)) * 255 * 255);
		else
			choose_color(x, y, p, i);
	}
}
