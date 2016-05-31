/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Sierpinski_carpet.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpressen <mpressen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/03 17:43:40 by mpressen          #+#    #+#             */
/*   Updated: 2016/05/31 19:11:51 by mpressen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	draw_sierpinski_carpet(t_fractolparam *p)
{
	int		x;
	int		y;

	x = -1;
	while (++x < p->width)
	{
		y = -1;
		while (++y < p->height)
			if (!(x % 3 == 1 && y % 3 == 1) && !((x / 3) % 3 == 1
				&& (y / 3) % 3 == 1) && !((x / 9) % 3 == 1 && (y
				/ 9) % 3 == 1) && !((x / 27) % 3 == 1 && (y / 27)
				% 3 == 1) && !((x / 81) % 3 == 1 && (y / 81) % 3 == 1))
				draw_pixel(x, y, p, 0xff00ff);
			else
				draw_pixel(x, y, p, 0x0000ff);
	}
}
