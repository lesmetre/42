/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpressen <mpressen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/03 17:35:19 by mpressen          #+#    #+#             */
/*   Updated: 2016/05/04 17:22:55 by mpressen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	draw_miniMandelbrot(t_fractolparam *param, int x, int y, int i)
{
	double	c_r;
    double	c_i;
    double	z_r;
    double	z_i;
    double	tmp;

    while (++x < 270)
    {
        c_r = (double)x / 100 - 2.1;
        y = -1;
        while (++y < 240)
        {
            c_i = (double)y / 100 - 1.2;
            z_r = 0;
            z_i = 0;
            i = -1;
            while (z_r * z_r + z_i * z_i < 4 && ++i < 50)
            {
                tmp = z_r;
                z_r = z_r * z_r - z_i * z_i + c_r;
                z_i = 2 * z_i * tmp + c_i;
            }
			mlx_pixel_put(param->mlx, param->win, x, y, i * 255 / 50);
        }
		mlx_pixel_put(param->mlx, param->win, x, y, 0xffffff);
    }
	y = -1;
	while (++y < 240)
		mlx_pixel_put(param->mlx, param->win, x, y, 0xffffff);
}

void		init_Julia(t_fractolparam **addr_param)
{
	t_fractolparam *param;

	param = *addr_param;
    param->x1 = -1;
    param->x2 = 1;
    param->y1 = -1.2;
    param->y2 = 1.2;
    param->iteration_max = 150;
    param->zoom = 500;
	draw_miniMandelbrot(param, -1, -1, -1);
}

void		draw_Julia(t_fractolparam *param, int x, int y, int i)
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
