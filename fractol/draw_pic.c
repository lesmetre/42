/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_pic.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpressen <mpressen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/05 19:43:33 by mpressen          #+#    #+#             */
/*   Updated: 2016/06/02 18:25:24 by mpressen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void		draw_pixel(int x, int y, t_fractolparam *p, int color)
{
	int pix;

	pix = x + y * p->width;
	if (x < p->width && x >= 0 && pix >= 0 && pix < p->pixmax)
		p->pic[pix] = mlx_get_color_value(p->mlx, color);
}

void		choose_color(int x, int y, t_fractolparam *p, int i)
{
	if (p->color == 1)
		draw_pixel(x, y, p, (i == p->imax ? 0xffffff : 0x000000));
	else if (p->color == 2)
		draw_pixel(x, y, p, (p->imax - i) * 255 * 255);
	else if (p->color == 3)
		draw_pixel(x, y, p, 0xff0000 - i * 256 + i + i * 255 * 255);
	else if (p->color == 4)
		draw_pixel(x, y, p, i * i * i * i);
	else if (p->color == 5)
		draw_pixel(x, y, p, i * p->imax * i * i);
	else if (p->color == 6)
		draw_pixel(x, y, p, log(log(sqrt(i * p->imax))) * 510);
	else if (p->color == 7)
		draw_pixel(x, y, p, log(i * p->imax) * 255 +
				log(i * p->imax) * 255 * 255 + log(i * p->imax));
	else if (p->color == 8)
		draw_pixel(x, y, p, 0xffffff - (p->imax * i) * 255);
	else if (p->color == 9)
		draw_pixel(x, y, p, i - (log(log(sqrt(p->z_r * p->z_r + p->z_i *
		p->z_i)))) / log(2) + (i - (log(log(sqrt(p->z_r * p->z_r + p->z_i
		* p->z_i)))) / log(2)) * 255 + (i - (log(log(sqrt(p->z_r * p->z_r
		+ p->z_i * p->z_i)))) / log(2)) * 255 * 255);
}

static void	draw_pic2(t_fractolparam *p)
{
	if (!ft_strcmp(p->fractal, "julia"))
		draw_julia(p);
	else if (!ft_strcmp(p->fractal, "mandelbrot"))
		draw_mandelbrot(p);
	else if (!ft_strcmp(p->fractal, "mpressen"))
		draw_mpressen(p);
	else if (!ft_strcmp(p->fractal, "sierpinski_triangle"))
		draw_sierpinski_triangle(p);
	else if (!ft_strcmp(p->fractal, "sierpinski_carpet"))
		draw_sierpinski_carpet(p);
	else if (!ft_strcmp(p->fractal, "burning_ship"))
		draw_burning_ship(p);
	else if (!ft_strcmp(p->fractal, "logbrot"))
		draw_logbrot(p);
	else if (!ft_strcmp(p->fractal, "multibrot"))
		draw_multibrot(p);
	else if (!ft_strcmp(p->fractal, "mandelbar"))
		draw_mandelbar(p);
	else if (!ft_strcmp(p->fractal, "multibar"))
		draw_multibar(p);
	mlx_put_image_to_window(p->mlx, p->win, p->img, 0, 0);
	mlx_destroy_image(p->mlx, p->img);
}

void		draw_pic(t_fractolparam **addr_p)
{
	t_fractolparam	*p;

	p = *addr_p;
	p->img = mlx_new_image(p->mlx, p->width, p->height);
	p->pic = (unsigned int *)mlx_get_data_addr(p->img,
			&p->bpp, &p->sizeline, &p->endian);
	draw_pic2(p);
	draw_legend(p);
}

void		mouse_hook2(int button, t_fractolparam *p)
{
	if (button == 5)
	{
		p->zoom *= 1.1;
		if ((int)p->zoom % 2)
			p->imax += 1;
	}
	else if (button == 4)
	{
		p->zoom *= 0.9;
		if ((int)p->zoom % 2)
			p->imax -= 1;
	}
}
