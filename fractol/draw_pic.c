/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_pic.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpressen <mpressen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/05 19:43:33 by mpressen          #+#    #+#             */
/*   Updated: 2016/05/03 19:04:07 by mpressen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	draw_pixel(int x, int y, t_fractolparam *param, int color)
{
	int pix;

	pix = x + y * param->image_x;
	if (x < param->image_x && x >= 0 && pix >= 0 && pix < param->pixmax)
		param->pic[pix] = mlx_get_color_value(param->mlx, color);
}
void	draw_pic(t_fractolparam **addr_param)
{
	t_fractolparam	*param;

	param = *addr_param;
	param->image_x = (param->x2 - param->x1) * param->zoom;
    param->image_y = (param->y2 - param->y1) * param->zoom;
	param->pixmax = param->image_x * param->image_y;
    param->img = mlx_new_image(param->mlx, param->image_x, param->image_y);
	param->pic = (unsigned int *)mlx_get_data_addr(param->img,
		&param->bpp, &param->sizeline, &param->endian);
	if (!ft_strcmp(param->fractal, "Julia"))
		draw_Julia(param, -1, -1 ,-1);
	else if (!ft_strcmp(param->fractal, "Mandelbrot"))
		draw_Mandelbrot(param, -1, -1, -1);
	else if (!ft_strcmp(param->fractal, "Burning_ship"))
		draw_Burning_ship(param, -1, -1, -1);
	else if (!ft_strcmp(param->fractal, "Sierpinski_triangle"))
		draw_Sierpinski_triangle(param);
	else if (!ft_strcmp(param->fractal, "Multibrot"))
		draw_Multibrot(param, -1, -1 ,-1);
	else if (!ft_strcmp(param->fractal, "Mandelbar"))
		draw_Mandelbar(param, -1, -1 ,-1);
	else if (!ft_strcmp(param->fractal, "Sierpinski_carpet"))
		draw_Sierpinski_carpet(param);
	else if (!ft_strcmp(param->fractal, "Multibar"))
		draw_Multibar(param, -1, -1 ,-1);
	mlx_put_image_to_window(param->mlx, param->win, param->img, (param->width - param->image_x) * 0.5, (param->height - param->image_y) * 0.5);
}
