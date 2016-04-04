/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpressen <mpressen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/04 16:18:13 by mpressen          #+#    #+#             */
/*   Updated: 2016/04/04 17:01:12 by mpressen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void		draw_pixel(int x1, int y1, t_fdf *param)
{
}

void			draw_line(t_fdf *start, t_fdf *end, t_fdf *param)
{
	float	xab;
	float	yab;
	float	lab;
	int		i;

	xab = end->x1 - start->x1;
	yab = end->y1 - start->y1;
	lab = sqrt(xab * xab + yab * yab);
	i = -1;
	xab /= lab;
	yab /= lab;
	while (++i <= lab)
		draw_pixel(x1 + i * xab, y1 + i * yab, param);
}
