/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpressen <mpressen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/03 17:35:19 by mpressen          #+#    #+#             */
/*   Updated: 2016/05/04 13:06:54 by mpressen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	init_Julia(t_fractolparam **addr_param)
{
    (*addr_param)->x1 = -1;
    (*addr_param)->x2 = 1;
    (*addr_param)->y1 = -1.2;
    (*addr_param)->y2 = 1.2;
    (*addr_param)->iteration_max = 150;
    (*addr_param)->zoom = 500;
}

void	draw_Julia(t_fractolparam *param, int x, int y, int i)
{
    double  c_r;
    double  c_i;
    double  z_r;
    double  z_i;
    double  tmp;

    while (++x < param->image_x && x / param->zoom < param->width)
    {
        c_r = param->mousex;
        y = -1;
        while (++y < param->image_y && y / param->zoom < param->height)
        {
            c_i = param->mousey;
            z_r = x / param->zoom + param->x1;
            z_i = y / param->zoom + param->y1;
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
