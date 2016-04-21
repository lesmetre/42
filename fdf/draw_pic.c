/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_pic.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpressen <mpressen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/05 19:43:33 by mpressen          #+#    #+#             */
/*   Updated: 2016/04/21 22:08:16 by mpressen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void		draw_pixel(int x, int y, t_fdfparam *param, int color)
{
	int		pix;

	pix = x + y * param->width + param->midwidth
		+ param->midheight * param->width;
	if (x + param->midwidth < param->width && x + param->midwidth >= 0
		&& pix >= 0 && pix <= param->pixmax && param->pic[pix] == 0)
	{
		if (color != -1)
			param->pic[pix] = mlx_get_color_value(param->mlx, color);
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

	param->x1 = param->modx * 0.71 * (start->x - start->y) * param->zoom;
	param->x2 = param->modx * 0.71 * (end->x - end->y) * param->zoom;
	xab = param->x2 - param->x1;
	param->y1 = (param->mody * 0.41 * (start->x + start->y) - param->modz
				* 0.82 * start->z) * param->zoom;
	param->y2 = (param->mody * 0.41 * (end->x + end->y) - param->modz
				* 0.82 * end->z) * param->zoom;
	yab = param->y2 - param->y1;
	lab = sqrt((xab * xab) + (yab * yab));
	i = -1;
	xab /= lab;
	yab /= lab;
	while (++i < lab * 0.5)
		draw_pixel((int)floor(param->x1 + i * xab + 0.5),
		(int)floor(param->y1 + i * yab + 0.5), param, start->color);
	i--;
	while (++i < lab)
		draw_pixel((int)floor(param->x1 + i * xab + 0.5),
		(int)floor(param->y1 + i * yab + 0.5), param, end->color);
}

static void		draw_legend(t_fdfparam *param)
{
	mlx_string_put(param->mlx, param->win, 10,
			param->height - 40, 0x00ffff, param->file);
	mlx_string_put(param->mlx,
			param->win, 10, 1, 0xff0000, "move map : arrow keys");
	mlx_string_put(param->mlx,
			param->win, 10, 21, 0xff0000, "zoom : + / -");
	mlx_string_put(param->mlx,
			param->win, 10, 41, 0xff0000, "modify perspective : 4-7 / 5-8");
	mlx_string_put(param->mlx,
			param->win, 10, 61, 0xff0000, "alter height : 6-9");
	mlx_string_put(param->mlx,
			param->win, 10, 81, 0xff0000, "reinitiate : space");
	mlx_string_put(param->mlx,
			param->win, 10, 101, 0xff0000, "quit : q / echap");
}

void			draw_pic(t_fdflist *list, t_fdfparam *param)
{
	t_fdflist	*tmp;

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
	draw_legend(param);
}
