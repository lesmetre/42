/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Sierpinski_triangle.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpressen <mpressen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/03 17:39:40 by mpressen          #+#    #+#             */
/*   Updated: 2016/06/03 15:05:54 by mpressen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	draw_sierpinski_triangle(t_fractolparam *p)
{
	int	x;
	int	y;
	int w;
	int z;

	x = -1;
	while (++x < p->width)
	{
		w = ((x - p->movex) / p->zoom + p->x1 + 2.4) * 10000;
		y = -1;
		while (++y < p->height)
		{
			z = ((y - p->movey) / p->zoom + p->y1 + 2.4) * 10000;
			if (!(w & z))
				draw_pixel(x, y, p, 0x00ff00);
			else
				draw_pixel(x, y, p, 0xff0000);
		}
	}
}
