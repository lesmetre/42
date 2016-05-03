/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpressen <mpressen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/20 17:34:07 by mpressen          #+#    #+#             */
/*   Updated: 2016/05/03 18:18:52 by mpressen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static int		expose_hook(t_fractolparam *param)
{
	mlx_destroy_image(param->mlx, param->img);
	mlx_clear_window(param->mlx, param->win);
	param->img = mlx_new_image(param->mlx, param->image_x, param->image_y);
	param->pic = (unsigned int *)(mlx_get_data_addr(param->img,
		&param->bpp, &param->sizeline, &param->endian));
	draw_pic(&param);
	return (0);
}

int				key_hook(int keycode, t_fractolparam *param)
{
	if (keycode == 53 || keycode == 12)
		exit(EXIT_SUCCESS);
	else if (keycode == 69)
		param->zoom += 10;
	else if (keycode == 78)
		param->zoom -= 10;
	expose_hook(param);
	return (0);
}
