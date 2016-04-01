/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpressen <mpressen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/23 14:07:11 by mpressen          #+#    #+#             */
/*   Updated: 2016/04/01 19:07:36 by mpressen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	draw_line(int x1, int y1, int x2, int y2)
{
	int dx;
	int dy;
	int e;

	if ((dx = x2 - x1) != 0)
	{
		if (dx > 0)
		{
			if ((dy = y2 - y1) != 0)
			{
				if (dy > 0)
				{
					if (dx >= dy)
					{
						e = dx;
						dx *= 2;
						dy *= 2;
						while (x1 != x2)
						{
							draw_pix(x1, y1);
							if ((e -= dy) < 0)
							{
								y1++;
								e += dx;
							}
							x1++;
						}
					}
					else
					{
						e = dy;
						dx *= 2;
						dy *= 2;
						while (y1 != y2)
						{
							draw_pix(x1, y1);
							if ((e -= dx) < 0)
							{
								x1++;
								e += dy;
							}
							y1++;
						}
					}
				}
				else
				{
					if (dx >= -dy)
					{
						e = dy;
						dx *= 2;
						dy *= 2;
						while (x1 != x2)
						{
							draw_pix(x1, y1);
							if ((e += dy) < 0)
							{
								y1--;
								e += dx;
							}
							x1++;
						}
					}
				}
			}
			else
			{
				while (x1 != x2)
				{
					draw_pix(x1, y1);
					x1++;
				}
			}
		}
		else
		{
			if ((dy = y2 - y1) != 0)
			{
				if (dy > 0)
				{
					if (-dx >= dy)
					{
						e = dx;
						dx *= 2;
						dy *= 2;
						while (x1 != x2)
						{
							draw_pix(x1, y1);
							if ((e += dy) >= 0)
							{
								y1++;
								e += dx;
							}
							x1--;
						}
					}
					else
					{
						e = dy;
						dx *= 2;
						dy *= 2;
						while (y1 != y2)
						{
							draw_pix(x1, y1);
							if ((e += dx) <= 0)
							{
								x1--;
								e += dy;
							}
							y1++;
						}
					}
				}
				else
				{
					if (dx <= dy)
					{
						e = dx;
						dx *= 2;
						dy *= 2;
						while (x1 != x2)
						{
							draw_pix(x1, y1);
							if ((e -= dy) >= 0)
							{
								y1--;
								e += dx;
							}
							x1--;
						}
					}
					else
					{
						e = dy;
						dx *= 2;
						dy *= 2;
						while (y1 != y2)
						{
							draw_pix(x1, y1);
							if ((e -= dx) >= 0)
							{
								x1--;
								e += dy;
							}
							y1--;
						}
					}
				}
			}
			else
			{
				while (x1 != x2)
				{
					draw_pix(x1, y1);
					x1--;
				}
			}
		}
	}
	else
	{
		if ((dy = y2 - y1) != 0)
		{
			if (dy > 0)
			{
				while (y1 != y2)
				{
					draw_pix(x1, y1);
					y1++;
				}
			}
			else
			{
				while (y1 != y2)
				{
					draw_pix(x1, y1);
					y1--;
				}
			}
		}
	}
}
