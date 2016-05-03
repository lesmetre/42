/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Mandelbar.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpressen <mpressen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/03 17:22:15 by mpressen          #+#    #+#             */
/*   Updated: 2016/05/03 19:10:47 by mpressen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	init_Mandelbar(t_fractolparam **addr_param)
{
	(*addr_param)->x1 = -2.1;
	(*addr_param)->x2 = 2.1;
	(*addr_param)->y1 = -2.1;
	(*addr_param)->y2 = 2.1;
	(*addr_param)->iteration_max = 50;
    (*addr_param)->zoom = 400;
}

void	draw_Mandelbar(t_fractolparam *param, int x, int y, int i)
{
	double	c_r;
	double	c_i;
	double	z_r;
	double	z_i;
	double	tmp;

	while (++x < param->image_x)
	{
		c_r = x / param->zoom + param->x1;
		y = -1;
		while (++y < param->image_y)
		{
			c_i = y / param->zoom + param->y1;
			z_r = 0;
			z_i = 0;
			i = -1;
			while (z_r * z_r + z_i * z_i < 4 && ++i < param->iteration_max)
			{
				tmp = z_r;
				z_r = z_r * z_r - z_i * z_i + c_r;
				z_i = -1 * (2 * z_i * tmp + c_i);
			}
			draw_pixel(x, y, param, i - (log(log(sqrt(z_r * z_r + z_i * z_i)))) / log(2)
					   + (i - (log(log(sqrt(z_r * z_r + z_i * z_i)))) / log(2)) * 256
					   + (i- (log(log(sqrt(z_r * z_r + z_i * z_i)))) / log(2)) * 256 * 256);
		}
	}
}