/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_pic.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpressen <mpressen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/05 19:43:33 by mpressen          #+#    #+#             */
/*   Updated: 2016/05/05 18:35:29 by mpressen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	draw_pixel(int x, int y, t_fractolparam *param, int color)
{
	int pix;

	pix = param->movex + x + y * param->image_x + param->movey * param->image_x;
	if (x + param->movex < param->image_x && x + param->movex >= 0 && pix >= 0 && pix < param->pixmax)
		param->pic[pix] = mlx_get_color_value(param->mlx, color);
}
void	draw_pic(t_fractolparam **addr_param)
{
	t_fractolparam	*param;

	param = *addr_param;
    param->img = mlx_new_image(param->mlx, param->image_x, param->image_y);
	param->pic = (unsigned int *)mlx_get_data_addr(param->img,
		&param->bpp, &param->sizeline, &param->endian);
	if (!ft_strcmp(param->fractal, "Julia"))
	{
		draw_miniMandelbrot(param, -1, -1, -1);
		draw_Julia(param, -1, -1 ,-1);
	}
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
	mlx_put_image_to_window(param->mlx, param->win, param->img, 0, 0);
}
