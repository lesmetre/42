/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpressen <mpressen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/12 01:10:10 by mpressen          #+#    #+#             */
/*   Updated: 2016/04/10 18:12:58 by mpressen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void		display_init(t_fdf **addr_param)
{
	t_fdf	*param;

	param = *addr_param;
	param->width = 1920;
	param->height = 1080; 
	param->mlx = mlx_init();
	param->win = mlx_new_window(param->mlx, param->width, param->height, "FdF");
	param->img = mlx_new_image(param->mlx, param->width, param->height);
	param->pic = (unsigned int *)mlx_get_data_addr
		(param->img, &param->bpp, &param->sizeline, &param->endian);
	param->move = 0;
	param->zoom = 1;
}

static int		expose_hook(t_fdf *param)
{
	mlx_destroy_image(param->mlx, param->img);
	param->img = mlx_new_image(param->mlx, param->width, param->height);
	param->pic = (unsigned int *)mlx_get_data_addr
		(param->img, &param->bpp, &param->sizeline, &param->endian);
	draw_pic(param);
	return (0);
}

static int		key_hook(int keycode, t_fdf *param)
{
	static int		i = 0;
	static double	j = 1;
	if (keycode == 53 || keycode == 12)
		exit(EXIT_SUCCESS);
	else if (keycode == 123) // left
		i -= 50;
	else if (keycode == 124) // right
		i += 50;
	else if (keycode == 125) // down
		i += param->width * 50;
	else if (keycode == 126) // up
		i -= param->width * 50;
	else if (keycode == 49)
	{
		i = 0;
		j = 1;
	}
	else if (keycode == 69) // zoom
		j += 0.1;
	else if (keycode == 78 && j > 0.1) // dezoom
		j -= 0.1;
	param->move = i;
	param->zoom = j;
	expose_hook(param);
	return (0);
}

int				main(int ac, char **av)
{
	t_fdf			*param;

	if (ft_parsing(ac, av, &param))
		return (1);
	display_init(&param);
	draw_pic(param);
	mlx_key_hook(param->win, key_hook, param);
//	mlx_expose_hook(param->win, expose_hook, param);
	mlx_loop(param->mlx);
	return (0);
}
