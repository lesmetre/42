/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_pic.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpressen <mpressen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/05 19:43:33 by mpressen          #+#    #+#             */
/*   Updated: 2016/05/27 15:12:04 by mpressen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	draw_pixel(int x, int y, t_fractolparam *param, int color)
{
	int pix;

	pix = x + param->movex + (y + param->movey) * param->width;
	if (x + param->movex < param->width && x + param->movex >= 0 && pix >= 0 && pix < param->pixmax)
		param->pic[pix] = mlx_get_color_value(param->mlx, color);
}
void	draw_pic(t_fractolparam **addr_param)
{
	t_fractolparam	*param;

	param = *addr_param;;
    param->img = mlx_new_image(param->mlx, param->width, param->height);
	param->pic = (unsigned int *)mlx_get_data_addr(param->img,
		&param->bpp, &param->sizeline, &param->endian);
	if (!ft_strcmp(param->fractal, "Julia"))
		draw_Julia(param);
	else if (!ft_strcmp(param->fractal, "Mandelbrot"))
		draw_Mandelbrot(param);
	else if (!ft_strcmp(param->fractal, "Mpressen"))
		draw_Mpressen(param);
	else if (!ft_strcmp(param->fractal, "Sierpinski_triangle"))
		draw_Sierpinski_triangle(param);
	else if (!ft_strcmp(param->fractal, "Sierpinski_carpet"))
		draw_Sierpinski_carpet(param);
	else if (!ft_strcmp(param->fractal, "Burning_ship"))
		draw_Burning_ship(param);
	else if (!ft_strcmp(param->fractal, "Logbrot"))
		draw_Logbrot(param);
	else if (!ft_strcmp(param->fractal, "Multibrot"))
		draw_Multibrot(param);
	else if (!ft_strcmp(param->fractal, "Mandelbar"))
		draw_Mandelbar(param);
	else if (!ft_strcmp(param->fractal, "Multibar"))
	draw_Multibar(param);
	mlx_put_image_to_window(param->mlx, param->win, param->img, 0, 0);
}
