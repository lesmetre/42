/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Sierpinski_carpet.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpressen <mpressen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/03 17:43:40 by mpressen          #+#    #+#             */
/*   Updated: 2016/05/27 15:08:02 by mpressen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

/*
void    init_Sierpinski_carpet(t_fractolparam **addr_param)
{
    (*addr_param)->x1 = 0;
    (*addr_param)->x2 = 2.43;
    (*addr_param)->y1 = 0;
    (*addr_param)->y2 = 2.43;
    (*addr_param)->zoom = 400;
}
*/

void     draw_Sierpinski_carpet(t_fractolparam *param)
{
    int     x;
    int     y;

    x = -1;
    while (++x < param->width)
    {
        y = -1;
        while (++y < param->height)
            if (!(x % 3 == 1 && y % 3 == 1) && !((x / 3) % 3 == 1 && (y / 3) % 3 == 1)
                && !((x / 9) % 3 == 1 && (y / 9) % 3 == 1) && !((x / 27) % 3 == 1
																&& (y / 27) % 3 == 1) && !((x / 81) % 3 == 1 && (y / 81) % 3 == 1))
                draw_pixel(x, y, param, 0xff00ff);
			else
                draw_pixel(x, y, param, 0x0000ff);
    }
}
