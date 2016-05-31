/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Burning_ship.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpressen <mpressen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/03 17:33:33 by mpressen          #+#    #+#             */
/*   Updated: 2016/05/31 19:09:46 by mpressen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	draw_burning_ship2(t_fractolparam **addr_p)
{
	t_fractolparam	*p;

	p = *addr_p;
	p->tmp = p->z_r;
	p->z_r = fabs(p->z_r * p->z_r - p->z_i * p->z_i + p->c_r);
	p->z_i = fabs(2 * p->z_i * p->tmp + p->c_i);
}

void		draw_burning_ship(t_fractolparam *p)
{
	int y;
	int x;
	int i;

	y = -1;
	while (++y < p->height)
	{
		p->c_i = y / p->zoom + p->y1;
		x = -1;
		while (++x < p->width)
		{
			p->c_r = x / p->zoom + p->x1;
			p->z_r = 0;
			p->z_i = 0;
			i = -1;
			while (p->z_r * p->z_r + p->z_i * p->z_i < 4 && ++i < p->imax)
				draw_burning_ship2(&p);
			choose_color(x, y, p, i);
		}
	}
}
