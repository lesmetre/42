/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpressen <mpressen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/20 17:34:07 by mpressen          #+#    #+#             */
/*   Updated: 2016/04/21 20:39:16 by mpressen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static int		expose_hook(t_fdfparam *param)
{
	mlx_destroy_image(param->mlx, param->img);
	mlx_clear_window(param->mlx, param->win);
	param->img = mlx_new_image(param->mlx, param->width, param->height);
	param->pic = (unsigned int *)(mlx_get_data_addr(param->img,
		&param->bpp, &param->sizeline, &param->endian));
	ft_bzero(param->pic, param->pixmax);
	draw_pic(param->list, param);
	return (0);
}

static void		move(int keycode, t_fdfparam *param)
{
	if (keycode == 123)
		param->midwidth -= 50;
	else if (keycode == 124)
		param->midwidth += 50;
	else if (keycode == 125)
		param->midheight += 50;
	else if (keycode == 126)
		param->midheight -= 50;
}

static void		reinitiate(t_fdfparam *param)
{
	param->midwidth = param->width * 0.5;
	param->midheight = param->height * 0.5;
	param->zoom = 1;
	param->modx = 1;
	param->mody = 1;
	param->modz = 1;
}

int				key_hook(int keycode, t_fdfparam *param)
{
	if (keycode == 53 || keycode == 12)
		exit(EXIT_SUCCESS);
	else if (keycode >= 123 && keycode <= 126)
		move(keycode, param);
	else if (keycode == 49)
		reinitiate(param);
	else if (keycode == 69)
		param->zoom++;
	else if (keycode == 78)
		param->zoom--;
	else if (keycode == 89)
		param->modx += 0.1;
	else if (keycode == 86)
		param->modx -= 0.1;
	else if (keycode == 91)
		param->mody += 0.1;
	else if (keycode == 87)
		param->mody -= 0.1;
	else if (keycode == 92)
		param->modz += 0.1;
	else if (keycode == 88)
		param->modz -= 0.1;
	expose_hook(param);
	return (0);
}
