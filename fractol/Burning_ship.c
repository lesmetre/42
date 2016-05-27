/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Burning_ship.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpressen <mpressen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/03 17:33:33 by mpressen          #+#    #+#             */
/*   Updated: 2016/05/27 16:25:23 by mpressen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void    draw_Burning_ship(t_fractolparam *param)
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
                param->z_r = fabs(param->z_r * param->z_r - param->z_i * param->z_i + param->c_r);
                param->z_i = fabs(2 * param->z_i * param->tmp + param->c_i);
            }
			choose_color(x, y, param, i);
        }
    }
}
