/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpressen <mpressen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/12 01:10:10 by mpressen          #+#    #+#             */
/*   Updated: 2016/04/04 17:01:22 by mpressen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void		display_init(t_fdf *param)
{
	int	width;
	int	height;

	width = 1000;
	height = 500; 
	param->mlx = mlx_init();
	param->win = mlx_new_window(param->mlx, width, height, "FdF");
	param->img = mlx_new_image(param->mlx, width, height);
	param->pic = (unsigned int*)mlx_get_data_addr
		(param->img, &param->bpp, &param->sizeline, &param->endian);
	param->sizeline /= 4;
	param->center = param->sizeline * height / 2 + param->sizeline / 2;
}

static void		draw_pic(t_fdf *param)
{
	int		pix;
	t_fdf	*browser;
	t_fdf	*tmp;

	browser = param;
	while (browser)
	{
//		pix = param->center + browser->x1 + browser->y1 * param->sizeline + 0.5; 
//		param->pic[pix] = mlx_get_color_value(param->mlx, 0xffffff);
		tmp = browser->next;
		if (tmp && browser->y == tmp->y)
			draw_line(browser, tmp, param);
		while (tmp && browser->x != tmp->x)
			tmp = tmp->next;
		if (tmp)
			draw_line(browser, tmp, param);
		browser = browser->next;
	}
	mlx_put_image_to_window((*param)->mlx,
			(*param)->win, (*param)->img,
			((*param)->width_win - (*param)->width_img) / 2,
			((*param)->height_win - (*param)->height_img) / 2);
}

static int		key_hook(int keycode, t_fdf *param)
{
	param = NULL;
	if (keycode == 53)
		exit(EXIT_SUCCESS);
	return (0);
}

int				main(int ac, char **av)
{
	t_fdf			param;

	if (ft_parsing(ac, av, &param))
		return (1);
	display_init(&param);
	draw_pic(&param);
	mlx_key_hook(param->win, key_hook, param);
	mlx_loop(param->mlx);
	return (0);
}
