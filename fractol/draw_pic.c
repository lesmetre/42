/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_pic.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpressen <mpressen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/05 19:43:33 by mpressen          #+#    #+#             */
/*   Updated: 2016/05/27 18:54:38 by mpressen         ###   ########.fr       */
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

void	choose_color(int x, int y, t_fractolparam *param, int i)
{
	if (param->color == 1)
		draw_pixel(x, y, param, (i == param->iteration_max ? 0xffffff : 0x000000));
	if (param->color == 2)
		draw_pixel(x, y, param, (param->iteration_max - i) * 255 * 255);
	if (param->color == 3)
		draw_pixel(x, y, param, 0xff0000 - i * 256 + i + i * 255 * 255);
	if (param->color == 4)
		draw_pixel(x, y, param, i * i * i * i);
	if (param->color == 5)
		draw_pixel(x, y, param, i * param->iteration_max * i * i);
	if (param->color == 6)
		draw_pixel(x, y, param, log(log(sqrt(i * param->iteration_max))) * 510);
	if (param->color == 7)
		draw_pixel(x, y, param, log(i * param->iteration_max) * 255 + log(i *
		param->iteration_max) * 255 * 255 + log(i * param->iteration_max));
	if (param->color == 8)
		draw_pixel(x, y, param, 0xffffff - (param->iteration_max * i) * 255);
	if (param->color == 9)
		draw_pixel(x, y, param, i - (log(log(sqrt(param->z_r * param->z_r + param->z_i
		* param->z_i)))) / log(2) + (i - (log(log(sqrt(param->z_r * param->z_r +
		param->z_i * param->z_i)))) / log(2)) * 255 + (i - (log(log(sqrt(param->z_r *
		param->z_r + param->z_i * param->z_i)))) / log(2)) * 255 * 255);
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
