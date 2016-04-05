/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_pic.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpressen <mpressen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/05 19:43:33 by mpressen          #+#    #+#             */
/*   Updated: 2016/04/05 20:59:43 by mpressen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void		draw_pixel(float x, float y, t_fdf param)
{
	int	pix;

	ft_putendl("on rentre dans draw_pixel");
	pix = param.center + x + y * param.sizeline + 0.5;
	param.pic[pix] = mlx_get_color_value(param.mlx, 0xffffff);
}

static void		draw_line(t_fdf start, t_fdf end, t_fdf param)
{
	float	xab;
	float	yab;
	float	lab;
	int		i;

	ft_putendl("on rentre dans draw_line");
	xab = end.x1 - start.x1;
	yab = end.y1 - start.y1;
	lab = sqrt(xab * xab + yab * yab);
	i = 0;
	xab /= lab;
	yab /= lab;
	while (++i < lab)
		draw_pixel(start.x1 + i * xab, start.y1 + i * yab, param);
}

void			draw_pic(t_fdf param)
{
    t_fdf   *browser;
    t_fdf   *tmp;

    browser = &param;
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
    mlx_put_image_to_window(param.mlx,
							param.win, param.img, 0, 0);
}
