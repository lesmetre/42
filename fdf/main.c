/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpressen <mpressen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/12 01:10:10 by mpressen          #+#    #+#             */
/*   Updated: 2016/04/10 14:16:15 by mpressen         ###   ########.fr       */
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
	param->win = mlx_new_window(param->mlx, 1920, 1080, "FdF");
	param->img = mlx_new_image(param->mlx, 1920, 1080);
	param->pic = (unsigned int *)mlx_get_data_addr
		(param->img, &param->bpp, &param->sizeline, &param->endian);
	param->center = param->width * param->height / 2 + param->width * 0.5;
}

static int		key_hook(int keycode, t_fdf *param)
{
	static int i = 1;

	if (keycode == 53 || keycode == 12)
		exit(EXIT_SUCCESS);
	if (keycode == 123) // left
		param->width--;
	if (keycode == 124) // right
		param->width++;
	if (keycode == 125) // down
		param->height++; 
	if (keycode == 126) // up
		param->height--; 
	if (keycode == 49) // zoom
	{
		i++;
		param->x *= i;
		param->y *= i;
		param->z *= i;
	}
	if (keycode == 51) // dezoom
	{
		i--;
		param->x *= i;
		param->y *= i;
		param->z *= i;
	}
	return (0);
}

int				main(int ac, char **av)
{
	t_fdf			*param;

	if (ft_parsing(ac, av, &param))
		return (1);
	display_init(&param);
	mlx_key_hook(param->win, key_hook, param);
	draw_pic(param);
	mlx_key_hook(param->win, key_hook, param);
//	mlx_hook( event 17);
	mlx_expose_hook(param->win, key_hook, param);
	mlx_loop(param->mlx);
	return (0);
}
