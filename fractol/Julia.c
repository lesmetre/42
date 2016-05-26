/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpressen <mpressen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/03 17:35:19 by mpressen          #+#    #+#             */
/*   Updated: 2016/05/26 18:48:02 by mpressen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void        *draw_Julia1(void *data)
{
	int				y;
	int				x;
	int				i;
	int				end;
	t_fractolparam	*param;

	param = (t_fractolparam*)data;
	end = param->height / 4;
	y = -1;
    while (++y <= end)
    {
        param->c_i = param->mousey / 100 - 1.2;
        x = -1;
        while (++x < param->width)
        {
            param->c_r = param->mousex / 100  - 2.1;
            param->z_r = x / param->zoom + param->x1;
            param->z_i = y / param->zoom + param->y1;
            i = -1;
            while (param->z_r * param->z_r + param->z_i * param->z_i < 4 && ++i < param->iteration_max)
            {
                param->tmp = param->z_r;
                param->z_r = param->z_r * param->z_r - param->z_i * param->z_i + param->c_r;
                param->z_i = 2 * param->z_i * param->tmp + param->c_i;
            }
			draw_pixel(x, y, param, 0xffffff - (param->iteration_max * i) * 255);
		}
	}
	return (NULL);
}

void        *draw_Julia2(void *data)
{
	int				y;
	int				x;
	int				i;
	int				end;
	t_fractolparam	*param;

	param = (t_fractolparam*)data;
	end = param->height / 2;
	y = param->height / 4;
    while (++y <= end)
    {
        param->c_i2 = param->mousey / 100 - 1.2;
        x = -1;
        while (++x < param->width)
        {
            param->c_r2 = param->mousex / 100 - 2.1;
            param->z_r2 = x / param->zoom + param->x1;
			param->z_i2 = y / param->zoom + param->y1;
            i = -1;
            while (param->z_r2 * param->z_r2 + param->z_i2 * param->z_i2 < 4 && ++i < param->iteration_max)
            {
                param->tmp2 = param->z_r2;
                param->z_r2 = param->z_r2 * param->z_r2 - param->z_i2 * param->z_i2 + param->c_r2;
                param->z_i2 = 2 * param->z_i2 * param->tmp2 + param->c_i2;
            }
			draw_pixel(x, y, param, 0xffffff - (param->iteration_max * i) * 255);
		}
	}
	return (NULL);
}

void        *draw_Julia3(void *data)
{
	int		y;
	int		x;
	int		i;
	int		end;
	t_fractolparam	*param;

	param = (t_fractolparam*)data;
	end = param->height / 4 * 3;
	y = param->height / 2;
    while (++y <= end)
    {
        param->c_i3 = param->mousey / 100 - 1.2;
        x = -1;
        while (++x < param->width)
        {
            param->c_r3 = param->mousex / 100 - 2.1;
            param->z_r3 = x / param->zoom + param->x1;
            param->z_i3 = y / param->zoom + param->y1;
            i = -1;
            while (param->z_r3 * param->z_r3 + param->z_i3 * param->z_i3 < 4 && ++i < param->iteration_max)
            {
                param->tmp3 = param->z_r3;
                param->z_r3 = param->z_r3 * param->z_r3 - param->z_i3 * param->z_i3 + param->c_r3;
                param->z_i3 = 2 * param->z_i3 * param->tmp3 + param->c_i3;
            }
			draw_pixel(x, y, param, 0xffffff - (param->iteration_max * i) * 255);
		}
	}

	return (NULL);
}

void        *draw_Julia4(void *data)
{
	int		y;
	int		x;
	int		i;
	t_fractolparam	*param;

	param = (t_fractolparam*)data;
	y = param->height / 4 * 3;
    while (++y <= param->height)
    {
        param->c_i4 = param->mousey / 100 - 1.2;
        x = -1;
        while (++x < param->width)
        {
            param->c_r4 = param->mousex / 100 - 2.1;
            param->z_r4 = x / param->zoom + param->x1;
            param->z_i4 = y / param->zoom + param->y1;
            i = -1;
            while (param->z_r4 * param->z_r4 + param->z_i4 * param->z_i4 < 4 && ++i < param->iteration_max)
            {
                param->tmp4 = param->z_r4;
                param->z_r4 = param->z_r4 * param->z_r4 - param->z_i4 * param->z_i4 + param->c_r4;
                param->z_i4 = 2 * param->z_i4 * param->tmp4 + param->c_i4;
            }
			draw_pixel(x, y, param, 0xffffff - (param->iteration_max * i) * 255);
		}
	}
	return (NULL);
}

void		draw_Julia(t_fractolparam *param)
{
	pthread_t	thread1;
	pthread_t	thread2;
	pthread_t	thread3;
	pthread_t	thread4;
	int			ret;

	if ((ret = pthread_create(&thread1, NULL, draw_Julia1, param)))
		exit(1);
	if ((ret = pthread_create(&thread2, NULL, draw_Julia2, param)))
		exit(1);
	if ((ret = pthread_create(&thread3, NULL, draw_Julia3, param)))
		exit(1);
	if ((ret = pthread_create(&thread4, NULL, draw_Julia4, param)))
		exit(1);
	pthread_join(thread1, NULL);
	pthread_join(thread2, NULL);
	pthread_join(thread3, NULL);
	pthread_join(thread4, NULL);
}

/*
void		draw_Julia(t_fractolparam *param)
{
	int y;
	int x;
	int i;

	y = -1;

    while (++y < param->height)
    {
        param->c_i = param->mousey / 100 - 1.2;
        x = -1;
        while (++x < param->width)
        {
            param->c_r = param->mousex / 100 - 2.1;
            param->z_r = x / param->zoom + param->x1;
			param->z_i = y / param->zoom + param->y1;
            i = -1;
            while (param->z_r * param->z_r + param->z_i * param->z_i < 4 && ++i < param->iteration_max)
            {
                param->tmp = param->z_r;
                param->z_r = param->z_r * param->z_r - param->z_i * param->z_i + param->c_r;
                param->z_i = 2 * param->z_i * param->tmp + param->c_i;
            }
			draw_pixel(x, y, param, 0xffffff - (param->iteration_max * i) * 255);
		}
	}
}
*/
