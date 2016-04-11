/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_pic.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpressen <mpressen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/05 19:43:33 by mpressen          #+#    #+#             */
/*   Updated: 2016/04/12 01:49:58 by mpressen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <stdio.h>
static void		draw_pixel(int x, int y, t_fdfparam *param)
{
	int		pix;

	pix = x + y * param->width + param->center;
	if (pix >= 0 && pix <= param->width * param->height)
		param->pic[pix] = mlx_get_color_value(param->mlx, 0xffffff);
}


static void		draw_line(t_fdflist *start, t_fdflist *end, t_fdfparam *param)
{
	double	xab;
	double	yab;
	int		lab;
	int		i;
	int		x1;
	int		y1;
	int		x2;
	int		y2;

	x1 = 0.71 * (start->x - start->y) * 20 + 0.5;
	y1 = (0.41 * (start->x + start->y) - 0.82 * start->z) * 20 + 0.5;
	x2 = 0.71 * (end->x - end->y) * 20 + 0.5;
	y2 = (0.41 * (end->x + end->y) - 0.82 * end->z) * 20 + 0.5;
	xab = (x2 - x1);
	yab = (y2 - y1);
	lab = sqrt((xab * xab) + (yab * yab));
	i = -1;
	xab /= lab;
	yab /= lab;
	while (++i < lab)
		draw_pixel(x1 + (i * xab), y1 + (i * yab), param);
}

void			draw_pic(t_fdflist *list, t_fdfparam *param)
{
    t_fdflist   *tmp;

    while (list)
    {
        tmp = list->next;
        if (tmp && list->y == tmp->y)
			draw_line(list, tmp, param);
        while (tmp && list->x != tmp->x)
            tmp = tmp->next;
        if (tmp)
			draw_line(list, tmp, param);
        list = list->next;
    }
    mlx_put_image_to_window(param->mlx,
							param->win, param->img, 0, 0);
}
