/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpressen <mpressen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/03 17:35:19 by mpressen          #+#    #+#             */
/*   Updated: 2016/05/31 20:00:59 by mpressen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void		*draw_mpressen1(void *data)
{
	int				y;
	int				x;
	int				i;
	int				end;
	t_fractolparam	*p;

	p = (t_fractolparam*)data;
	end = p->height / 4;
	y = -1;
	while (++y <= end)
	{
		p->c_i = p->mousey / 100 - 1.2;
		x = -1;
		while (++x < p->width)
		{
			p->c_r = p->mousex / 100 - 2.1;
			p->z_r = x / p->zoom + p->x1;
			p->z_i = y / p->zoom + p->y1;
			i = -1;
			while (p->z_r * p->z_r + p->z_i * p->z_i < 4 && ++i < p->imax)
			{
				p->tmp = p->z_r;
				p->z_r = fabs(p->z_r * p->z_r * p->z_r - 3 *
				p->z_r * p->z_i * p->z_i + p->c_r);
				p->z_i = -1 * (3 * p->tmp * p->tmp * p->z_i
				- p->z_i * p->z_i * p->z_i + p->c_i);
			}
			choose_color(x, y, p, i);
		}
	}
	return (NULL);
}

void		*draw_mpressen2(void *data)
{
	int				y;
	int				x;
	int				i;
	int				end;
	t_fractolparam	*p;

	p = (t_fractolparam*)data;
	end = p->height / 2;
	y = p->height / 4;
	while (++y <= end)
	{
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
				p->z_r2 = fabs(p->z_r2 * p->z_r2 * p->z_r2 - 3
				* p->z_r2 * p->z_i2 * p->z_i2 + p->c_r2);
				p->z_i2 = -1 * (3 * p->tmp2 * p->tmp2 * p->z_i2
				- p->z_i2 * p->z_i2 * p->z_i2 + p->c_i2);
			}
			if (p->color == 9)
				draw_pixel(x, y, p, i - (log(log(sqrt(p->z_r2 * p->z_r2 +
				p->z_i2 * p->z_i2)))) / log(2) + (i - (log(log(sqrt(p->z_r2
				* p->z_r2 + p->z_i2 * p->z_i2)))) / log(2)) * 255 + (i -
				(log(log(sqrt(p->z_r2 * p->z_r2 + p->z_i2 * p->z_i2))))
				/ log(2)) * 255 * 255);
			else
				choose_color(x, y, p, i);
		}
	}
	return (NULL);
}

void		*draw_mpressen3(void *data)
{
	int				y;
	int				x;
	int				i;
	int				end;
	t_fractolparam	*p;

	p = (t_fractolparam*)data;
	end = p->height / 4 * 3;
	y = p->height / 2;
	while (++y <= end)
	{
		p->c_i3 = p->mousey / 100 - 1.2;
		x = -1;
		while (++x < p->width)
		{
			p->c_r3 = p->mousex / 100 - 2.1;
			p->z_r3 = x / p->zoom + p->x1;
			p->z_i3 = y / p->zoom + p->y1;
			i = -1;
			while (p->z_r3 * p->z_r3 + p->z_i3 * p->z_i3 < 4 && ++i < p->imax)
			{
				p->tmp3 = p->z_r3;
				p->z_r3 = fabs(p->z_r3 * p->z_r3 * p->z_r3 - 3 *
				p->z_r3 * p->z_i3 * p->z_i3 + p->c_r3);
				p->z_i3 = -1 * (3 * p->tmp3 * p->tmp3 * p->z_i3
				- p->z_i3 * p->z_i3 * p->z_i3 + p->c_i3);
			}
			if (p->color == 9)
				draw_pixel(x, y, p, i - (log(log(sqrt(p->z_r3 * p->z_r3 +
				p->z_i3 * p->z_i3)))) / log(2) + (i - (log(log(sqrt(p->z_r3
				* p->z_r3 + p->z_i3 * p->z_i3)))) / log(2)) * 255 + (i -
				(log(log(sqrt(p->z_r3 * p->z_r3 + p->z_i3 * p->z_i3))))
				/ log(2)) * 255 * 255);
			else
				choose_color(x, y, p, i);
		}
	}
	return (NULL);
}

void		*draw_mpressen4(void *data)
{
	int				y;
	int				x;
	int				i;
	t_fractolparam	*p;

	p = (t_fractolparam*)data;
	y = p->height / 4 * 3;
	while (++y <= p->height)
	{
		p->c_i4 = p->mousey / 100 - 1.2;
		x = -1;
		while (++x < p->width)
		{
			p->c_r4 = p->mousex / 100 - 2.1;
			p->z_r4 = x / p->zoom + p->x1;
			p->z_i4 = y / p->zoom + p->y1;
			i = -1;
			while (p->z_r4 * p->z_r4 + p->z_i4 * p->z_i4 < 4 && ++i < p->imax)
			{
				p->tmp4 = p->z_r4;
				p->z_r4 = fabs(p->z_r4 * p->z_r4 * p->z_r4 -
				3 * p->z_r4 * p->z_i4 * p->z_i4 + p->c_r4);
				p->z_i4 = -1 * (3 * p->tmp4 * p->tmp4 * p->z_i4
				- p->z_i4 * p->z_i4 * p->z_i4 + p->c_i4);
			}
			if (p->color == 9)
				draw_pixel(x, y, p, i - (log(log(sqrt(p->z_r4 * p->z_r4 +
				p->z_i4 * p->z_i4)))) / log(2) + (i - (log(log(sqrt(p->z_r4
				* p->z_r4 + p->z_i4 * p->z_i4)))) / log(2)) * 255 + (i -
				(log(log(sqrt(p->z_r4 * p->z_r4 + p->z_i4 * p->z_i4))))
				/ log(2)) * 255 * 255);
			else
				choose_color(x, y, p, i);
		}
	}
	return (NULL);
}

void		draw_mpressen(t_fractolparam *p)
{
	pthread_t	thread1;
	pthread_t	thread2;
	pthread_t	thread3;
	pthread_t	thread4;
	int			ret;

	if ((ret = pthread_create(&thread1, NULL, draw_mpressen1, p)))
		exit(1);
	if ((ret = pthread_create(&thread2, NULL, draw_mpressen2, p)))
		exit(1);
	if ((ret = pthread_create(&thread3, NULL, draw_mpressen3, p)))
		exit(1);
	if ((ret = pthread_create(&thread4, NULL, draw_mpressen4, p)))
		exit(1);
	pthread_join(thread1, NULL);
	pthread_join(thread2, NULL);
	pthread_join(thread3, NULL);
	pthread_join(thread4, NULL);
}
