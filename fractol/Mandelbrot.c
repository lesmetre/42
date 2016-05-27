/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpressen <mpressen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/03 17:17:06 by mpressen          #+#    #+#             */
/*   Updated: 2016/05/27 14:07:29 by mpressen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	draw_Mandelbrot(t_fractolparam *param)
{
	int y;
	int x;
	int i;

	y = -1;
	while (++y < param->height)
	{
		param->c_i = y / param->zoom + param->y1;
		x = -1;
		while (++x < param->width)
		{
			param->c_r = x / param->zoom + param->x1;			
			param->z_r = 0;
			param->z_i = 0;
			i = -1;
			while (param->z_r * param->z_r + param->z_i * param->z_i < 4 && ++i < param->iteration_max)
			{
				param->tmp = param->z_r;
				param->z_r = param->z_r * param->z_r - param->z_i * param->z_i + param->c_r;
				param->z_i = 2 * param->z_i * param->tmp + param->c_i;
			}
			draw_pixel(x, y, param, 0xffffff - (param->iteration_max * i) * 255);
		}
	}
}
