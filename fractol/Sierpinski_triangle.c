/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Sierpinski_triangle.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpressen <mpressen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/03 17:39:40 by mpressen          #+#    #+#             */
/*   Updated: 2016/05/04 12:04:10 by mpressen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void    init_Sierpinski_triangle(t_fractolparam **addr_param)
{

    (*addr_param)->x1 = -1.28;
    (*addr_param)->x2 = 1.28;
    (*addr_param)->y1 = -1.28;
    (*addr_param)->y2 = 1.28;
    (*addr_param)->zoom = 500;
}

void     draw_Sierpinski_triangle(t_fractolparam *param)
{
    int     x;
    int     y;

    x = -1;
    while (++x < param->image_x)
    {
        y = -1;
        while (++y < param->image_y)
		{
            if (!(x & y))
                draw_pixel(x, y, param, 0x00ff00);
			else
				draw_pixel(x, y, param, 0xff0000);
		}
    }
}
