/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_pic.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpressen <mpressen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/05 19:43:33 by mpressen          #+#    #+#             */
/*   Updated: 2016/04/13 01:09:06 by mpressen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void		draw_pixel(int x, int y, t_fdfparam *param)
{
	int		pix;

	pix = x + y * param->width + param->center;
	if (pix >= 0 && pix <= param->width * param->height)
		param->pic[pix] = mlx_get_color_value(param->mlx, 0xffffff);
}


static void		draw_line(t_fdflist *start, t_fdflist *end, t_fdfparam *param)
{
	int		xab;
	int		yab;
	int		lab;
	int		i;
	int		tmp;

	param->x1 = 0.71 * (start->x - start->y) * 20 + 0.5;
	tmp = 0.71 * (end->x - end->y) * 20 + 0.5;
	xab = tmp - param->x1;
	param->y1  = (0.41 * (start->x + start->y) - 0.82 * start->z) * 20 + 0.5;
	tmp = (0.41 * (end->x + end->y) - 0.82 * end->z) * 20 + 0.5;
	yab = tmp - param->y1;
	lab = sqrt((xab * xab) + (yab * yab));
	i = -1;
	xab = xab * 1000 / lab;
	yab = yab * 1000 / lab;
	while (++i <= lab)
		draw_pixel(param->x1 + i * xab *0.001 + 0.5, param->y1 + i * yab * 0.001 + 0.5, param);
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
