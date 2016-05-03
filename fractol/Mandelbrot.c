/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpressen <mpressen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/03 17:17:06 by mpressen          #+#    #+#             */
/*   Updated: 2016/05/03 19:40:24 by mpressen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	init_Mandelbrot(t_fractolparam **addr_param)
{
	(*addr_param)->x1 = -2.1;
	(*addr_param)->x2 = 0.6;
	(*addr_param)->y1 = -1.2;
	(*addr_param)->y2 = 1.2;
	(*addr_param)->iteration_max = 50;
	(*addr_param)->zoom = 100;
}

void	draw_Mandelbrot(t_fractolparam *param, int x, int y, int i)
{
	double	c_r;
	double	c_i;
	double	z_r;
	double	z_i;
	double	tmp;

	while (++x < param->image_x && x / param->zoom < param->width)
	{
		c_r = x / param->zoom + param->x1;
		y = -1;
		while (++y < param->image_y && y / param->zoom < param->height)
		{
			c_i = y / param->zoom + param->y1;
			z_r = 0;
			z_i = 0;
			i = -1;
			while (z_r * z_r + z_i * z_i < 4 && ++i < param->iteration_max)
			{
				tmp = z_r;
				z_r = z_r * z_r - z_i * z_i + c_r;
				z_i = 2 * z_i * tmp + c_i;
			}
			draw_pixel(x, y, param, i - (log(log(sqrt(z_r * z_r + z_i * z_i)))) / log(2)
					   + (i - (log(log(sqrt(z_r * z_r + z_i * z_i)))) / log(2)) * 256
					   + (i- (log(log(sqrt(z_r * z_r + z_i * z_i)))) / log(2)) * 256 * 256);
		}
	}
}
