/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_legend.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpressen <mpressen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/02 12:04:42 by mpressen          #+#    #+#             */
/*   Updated: 2016/06/02 16:28:59 by mpressen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void		draw_legend(t_fractolparam *p)
{
	int x;
	int y;

	y = 1;
	x = 1;
	while (++y < p->height - 3)
	{
		mlx_pixel_put(p->mlx, p->win, p->width + 2, y, 0x00ff00);
		mlx_pixel_put(p->mlx, p->win, p->width + 197, y, 0x00ff00);
	}
	while (++x < 197)
	{
		mlx_pixel_put(p->mlx, p->win, x + p->width, 2, 0x00ff00);
		mlx_pixel_put(p->mlx, p->win, x + p->width, p->height - 3, 0x00ff00);
	}
    mlx_string_put(p->mlx, p->win, p->width + (200 - ft_strlen(p->fractal) * 10) / 2, 21, 0x00ffff, p->fractal);
    mlx_string_put(p->mlx, p->win, p->width + 10, 51, 0xff00ff, "move: arrow keys");
    mlx_string_put(p->mlx, p->win, p->width + 10, 71, 0xff00ff, "zoom: scroll");
    mlx_string_put(p->mlx, p->win, p->width + 10, 131, 0xff00ff, "center view: clic");
    mlx_string_put(p->mlx, p->win, p->width + 10, 91, 0xff00ff, "color set: 1-9");
    mlx_string_put(p->mlx, p->win, p->width + 10, 111, 0xff00ff, "iteration: + / -");
    mlx_string_put(p->mlx, p->win, p->width + 10, 151, 0xff00ff, "(un)freeze: space");
    mlx_string_put(p->mlx, p->win, p->width + 10, 171, 0xff00ff, "exit: echap / q");
    mlx_string_put(p->mlx, p->win, p->width + 10, 191, 0xff00ff, "reset: return");
    mlx_string_put(p->mlx, p->win, p->width + 10, 251, 0x0000ff, "zoom: ");
	if (p->zoom < 2147483648)
		mlx_string_put(p->mlx, p->win, p->width + 85, 251, 0x00ff00, ft_itoa_base(p->zoom, 10));
	else
		mlx_string_put(p->mlx, p->win, p->width + 83, 251, 0xff0000, "WooooooW !!!");
    mlx_string_put(p->mlx, p->win, p->width + 10, 271, 0x0000ff, "iteration:");
	mlx_string_put(p->mlx, p->win, p->width + 125, 271, 0x00ff00, ft_itoa_base(p->imax, 10));
    mlx_string_put(p->mlx, p->win, p->width + 10, 291, 0x0000ff, "freeze:");
	if(!p->block)
		mlx_string_put(p->mlx, p->win, p->width + 90, 291, 0x00ff00, "OFF");
	else
		mlx_string_put(p->mlx, p->win, p->width + 90, 291, 0xff0000, "ON");

}
