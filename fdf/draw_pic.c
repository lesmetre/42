/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_pic.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpressen <mpressen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/05 19:43:33 by mpressen          #+#    #+#             */
/*   Updated: 2016/04/20 02:58:32 by mpressen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void		draw_pixel(int x, int y, t_fdfparam *param, t_fdflist *start)
{
	int		pix;

	pix = x + y * param->width + param->center;
	if (pix >= 0 && pix <= param->pixmax)
	{
		if (start->color)
			param->pic[pix] = mlx_get_color_value(param->mlx, start->color);
		else
			param->pic[pix] = mlx_get_color_value(param->mlx, 0xffffff);
	}
}


static void		draw_line(t_fdflist *start, t_fdflist *end, t_fdfparam *param)
{
	double	xab;
	double	yab;
	double	lab;
	int		i;
	double	tmp;
	
	param->x1 = param->modx * 0.71 * (start->x - start->y) * param->zoom;
	tmp = param->modx * 0.71 * (end->x - end->y) * param->zoom;
	xab = tmp - param->x1;
	param->y1  = (param->mody * 0.41 * (start->x + start->y) - param->modz * 0.82 * start->z) * param->zoom;
	tmp = (param->mody * 0.41 * (end->x + end->y) - param->modz * 0.82 * end->z) * param->zoom;
	yab = tmp - param->y1;
	lab = sqrt((xab * xab) + (yab * yab));
	i = -1;
	xab /= lab;
	yab /= lab;
	while (++i < lab)
		draw_pixel((int)floor(param->x1 + i * xab + 0.5), (int)floor(param->y1 + i * yab + 0.5), param, start);
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
