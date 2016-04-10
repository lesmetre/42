/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_pic.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpressen <mpressen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/05 19:43:33 by mpressen          #+#    #+#             */
/*   Updated: 2016/04/10 12:49:10 by mpressen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void		draw_pixel(double x, double y, t_fdf *param)
{
	int	pix;

    x = ceil(param->width * 0.5 + x * 0.001 + 0.5);
    y = ceil(param->height * 0.5 + y * 0.001 + 0.5);
	pix = floor(x + y * param->width + 0.5);
	if (pix >= 0 && pix <= param->width * param->height) 
		param->pic[pix] = mlx_get_color_value(param->mlx, 0xffffff);
}

static void		draw_line(t_fdf start, t_fdf end, t_fdf *param)
{
	double	xab;
	double	yab;
	double	lab;
	int		i;

	xab = end.x1 - start.x1;
	yab = end.y1 - start.y1;
	lab = sqrt((xab * xab) + (yab * yab));
	i = 0;
	xab /= lab;
	yab /= lab;
	while (++i < lab)
		draw_pixel(floor(start.x1 + (i * xab) + 0.5), floor(start.y1 + (i * yab) + 0.5), param);
}

void			draw_pic(t_fdf *param)
{
    t_fdf   *browser;
    t_fdf   *tmp;

    browser = param;
    while (browser)
    {
		draw_pixel(browser->x1, browser->y1, param);
        tmp = browser->next;
        if (tmp && browser->y == tmp->y)
			draw_line(*browser, *tmp, param);
        while (tmp && browser->x != tmp->x)
            tmp = tmp->next;
        if (tmp)
			draw_line(*browser, *tmp, param);
        browser = browser->next;
    }
    mlx_put_image_to_window(param->mlx,
							param->win, param->img, 0, 0);
}
