/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Mandelbar.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpressen <mpressen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/03 17:22:15 by mpressen          #+#    #+#             */
/*   Updated: 2016/06/02 09:48:08 by mpressen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	draw_mandelbar(t_fractolparam *p)
{
	int y;
	int x;
	int i;

	y = -1;
	while (++y < p->height)
	{
		p->c_i = (y - p->movey) / p->zoom + p->y1;
		x = -1;
		while (++x < p->width)
		{
			p->c_r = (x - p->movex) / p->zoom + p->x1;
			p->z_r = 0;
			p->z_i = 0;
			i = -1;
			while (p->z_r * p->z_r + p->z_i * p->z_i < 4 && ++i < p->imax)
			{
				p->tmp = p->z_r;
				p->z_r = p->z_r * p->z_r - p->z_i * p->z_i + p->c_r;
				p->z_i = -1 * (2 * p->z_i * p->tmp + p->c_i);
			}
			choose_color(x, y, p, i);
		}
	}
}