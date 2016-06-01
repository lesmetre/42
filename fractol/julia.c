/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpressen <mpressen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/03 17:35:19 by mpressen          #+#    #+#             */
/*   Updated: 2016/06/01 17:02:09 by mpressen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void		*draw_julia1(void *data)
{
	int				y;
	int				x;
	int				end;
	t_fractolparam	*p;

	p = (t_fractolparam*)data;
	end = p->height / 4;
	y = -1;
	x = -1;
	while (++y <= end)
		draw_julia1bis(p, x, y);
	return (NULL);
}

static void		*draw_julia2(void *data)
{
	int				y;
	int				x;
	int				end;
	t_fractolparam	*p;

	p = (t_fractolparam*)data;
	y = p->height / 4;
	x = -1;
	end = p->height / 2;
	while (++y <= end)
		draw_julia2bis(p, x, y);
	return (NULL);
}

static void		*draw_julia3(void *data)
{
	int				y;
	int				x;
	int				end;
	t_fractolparam	*p;

	p = (t_fractolparam*)data;
	y = p->height / 2;
	x = -1;
	end = p->height / 4 * 3;
	while (++y <= end)
		draw_julia3bis(p, x, y);
	return (NULL);
}

static void		*draw_julia4(void *data)
{
	int				y;
	int				x;
	t_fractolparam	*p;

	p = (t_fractolparam*)data;
	y = p->height / 4 * 3;
	x = -1;
	while (++y <= p->height)
		draw_julia4bis(p, x, y);
	return (NULL);
}

void			draw_julia(t_fractolparam *p)
{
	pthread_t	thread1;
	pthread_t	thread2;
	pthread_t	thread3;
	pthread_t	thread4;
	int			ret;

	if ((ret = pthread_create(&thread1, NULL, draw_julia1, p)))
		exit(1);
	if ((ret = pthread_create(&thread2, NULL, draw_julia2, p)))
		exit(1);
	if ((ret = pthread_create(&thread3, NULL, draw_julia3, p)))
		exit(1);
	if ((ret = pthread_create(&thread4, NULL, draw_julia4, p)))
		exit(1);
	pthread_join(thread1, NULL);
	pthread_join(thread2, NULL);
	pthread_join(thread3, NULL);
	pthread_join(thread4, NULL);
}
