/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Sierpinski_triangle.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpressen <mpressen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/03 17:39:40 by mpressen          #+#    #+#             */
/*   Updated: 2016/05/31 19:12:48 by mpressen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	draw_sierpinski_triangle(t_fractolparam *p)
{
	int	x;
	int	y;

	x = -1;
	while (++x < p->width)
	{
		y = -1;
		while (++y < p->height)
		{
			if (!(x & y))
				draw_pixel(x, y, p, 0x00ff00);
			else
				draw_pixel(x, y, p, 0xff0000);
		}
	}
}
