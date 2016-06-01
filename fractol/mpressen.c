/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpressen <mpressen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/03 17:35:19 by mpressen          #+#    #+#             */
/*   Updated: 2016/06/01 17:05:50 by mpressen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void		*draw_mpressen1(void *data)
{
	int				y;
	int				x;
	int				i;
	int				end;
	t_fractolparam	*p;

	p = (t_fractolparam*)data;
	end = p->height / 4;
	y = -1;
	x = -1;
	i = -1;
	while (++y <= end)
		draw_mpressen1bis(p, x, y, i);
	return (NULL);
}

static void		*draw_mpressen2(void *data)
{
	int				y;
	int				x;
	int				i;
	int				end;
	t_fractolparam	*p;

	p = (t_fractolparam*)data;
	end = p->height / 2;
	y = p->height / 4;
	x = -1;
	i = -1;
	while (++y <= end)
		draw_mpressen2bis(p, x, y, i);
	return (NULL);
}

static void		*draw_mpressen3(void *data)
{
	int				y;
	int				x;
	int				i;
	int				end;
	t_fractolparam	*p;

	p = (t_fractolparam*)data;
	end = p->height / 4 * 3;
	y = p->height / 2;
	x = -1;
	i = -1;
	while (++y <= end)
		draw_mpressen3bis(p, x, y, i);
	return (NULL);
}

static void		*draw_mpressen4(void *data)
{
	int				y;
	int				x;
	int				i;
	t_fractolparam	*p;

	p = (t_fractolparam*)data;
	y = p->height / 4 * 3;
	x = -1;
	i = -1;
	while (++y <= p->height)
		draw_mpressen4bis(p, x, y, i);
	return (NULL);
}

void			draw_mpressen(t_fractolparam *p)
{
	pthread_t	thread1;
	pthread_t	thread2;
	pthread_t	thread3;
	pthread_t	thread4;
	int			ret;

	if ((ret = pthread_create(&thread1, NULL, draw_mpressen1, p)))
		exit(1);
	if ((ret = pthread_create(&thread2, NULL, draw_mpressen2, p)))
		exit(1);
	if ((ret = pthread_create(&thread3, NULL, draw_mpressen3, p)))
		exit(1);
	if ((ret = pthread_create(&thread4, NULL, draw_mpressen4, p)))
		exit(1);
	pthread_join(thread1, NULL);
	pthread_join(thread2, NULL);
	pthread_join(thread3, NULL);
	pthread_join(thread4, NULL);
}
