/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_pic.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpressen <mpressen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/05 19:43:33 by mpressen          #+#    #+#             */
/*   Updated: 2016/04/28 17:15:35 by mpressen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void		draw_pixel(int x, int y, t_fractolparam *param, int color)
{
	int pix;

	pix = x + y * param->image_x;
	if (x < param->image_x && x >= 0 && pix >= 0 && pix < param->pixmax)
		param->pic[pix] = mlx_get_color_value(param->mlx, color); 
}

static void		draw_Mandelbraut(t_fractolparam *param, int x, int y, int i)
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
				z_i = 2 * z_i * tmp + c_i;
			}
			if (i == param->iteration_max)
				draw_pixel(x, y, param, 0x000000);
			else
				draw_pixel(x, y, param, i * 255 / param->iteration_max);
		}
	}
}

static void		draw_Julia(t_fractolparam *param, int x, int y, int i)
{
	double	c_r;
	double	c_i;
	double	z_r;
	double	z_i;
	double	tmp;

	while (++x < param->image_x)
	{
		c_r = 0.285;
		y = -1;
		while (++y < param->image_y)
		{
			c_i = 0.01;
			z_r = x / param->zoom + param->x1;
			z_i = y / param->zoom + param->y1;
			i = -1;
			while (z_r * z_r + z_i * z_i < 4 && ++i < param->iteration_max)
			{
				tmp = z_r;
				z_r = z_r * z_r - z_i * z_i + c_r;
				z_i = 2 * z_i * tmp + c_i;
			}
			if (i == param->iteration_max)
				param->pic[x + y * param->image_x] = mlx_get_color_value(param->mlx, 0x000000);
			else
				param->pic[x + y * param->image_x] = mlx_get_color_value(param->mlx, i * 255 / param->iteration_max);
		}
	}
}

void			draw_pic(t_fractolparam *param)
{
	if (!ft_strcmp(param->fractal, "Mandelbraut"))
		draw_Mandelbraut(param, -1, -1, -1);
	else if (!ft_strcmp(param->fractal, "Julia"))
		draw_Julia(param, -1, -1 ,-1);
	mlx_put_image_to_window(param->mlx, param->win, param->img, 0, 0);
}
