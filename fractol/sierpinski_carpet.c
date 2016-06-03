/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Sierpinski_carpet.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpressen <mpressen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/03 17:43:40 by mpressen          #+#    #+#             */
/*   Updated: 2016/06/03 14:59:29 by mpressen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	draw_sierpinski_carpet(t_fractolparam *p)
{
	int		x;
	int		y;
	int		w;
	int		z;

	x = -1;
	while (++x < p->width)
	{
		w = ((x - p->movex) / p->zoom + p->x1 + 100000) * 100;
		y = -1;
		while (++y < p->height)
		{
			z = ((y - p->movey) / p->zoom + p->y1 + 100000) * 100;
			if (!(w % 3 == 1 && z % 3 == 1) && !((w / 3) % 3 == 1
				&& (z / 3) % 3 == 1) && !((w / 9) % 3 == 1 && (z
				/ 9) % 3 == 1) && !((w / 27) % 3 == 1 && (z / 27)
				% 3 == 1) && !((w / 81) % 3 == 1 && (z / 81) % 3 == 1))
				draw_pixel(x, y, p, 0xff00ff);
			else
				draw_pixel(x, y, p, 0x0000ff);
		}
	}
}
