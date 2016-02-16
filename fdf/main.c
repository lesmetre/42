/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpressen <mpressen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/12 01:10:10 by mpressen          #+#    #+#             */
/*   Updated: 2016/02/16 13:36:40 by mpressen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void		display_init(t_fdf **param)
{
	(*param)->mlx = mlx_init();
	(*param)->width_win = 1920;
	(*param)->height_win = 1080;
	(*param)->win = mlx_new_window((*param)->mlx,
			(*param)->width_win, (*param)->height_win, "FdF");
	(*param)->width_img = 1920;
	(*param)->height_img = 1080;
	(*param)->img = mlx_new_image((*param)->mlx,
			(*param)->width_img, (*param)->height_img);
	(*param)->pic = (unsigned int*)mlx_get_data_addr((*param)->img,
			&(*param)->bpp, &(*param)->sizeline, &(*param)->endian);
	ft_putendl("--------------------------");
	ft_putstr("bpp a la valeur de ");
	ft_putnbr((*param)->bpp);
	ft_putendl(".");
	ft_putstr("sizeline a la valeur de ");
	ft_putnbr((*param)->sizeline);
	ft_putendl(".");
	ft_putstr("endian a la valeur de ");
	ft_putnbr((*param)->endian);
	ft_putendl(".");
	ft_putendl("--------------------------");
}

static void		draw_pic(t_fdf **param)
{
	int		i;
	t_fdf	*browser;

	ft_putendl("on rentre dans draw_pic");
	browser = *param;
	while (browser)
	{
		i = 0;
		ft_putstr("param->x a la valeur de ");
		ft_putnbr(browser->x);
		ft_putendl(".");
		ft_putstr("param->y a la valeur de ");
		ft_putnbr(browser->y);
		ft_putendl(".");
		i = (browser->x * 4) + (browser->y * (*param)->sizeline);
		ft_putstr("i a la valeur de ");
		ft_putnbr(i);
		ft_putendl(".");
		(*param)->pic[i] = mlx_get_color_value((*param)->mlx, 0xff0000);
		ft_putendl("on a illumine un pixel");
		browser = browser->next;
	}
	mlx_put_image_to_window((*param)->mlx,
			(*param)->win, (*param)->img,
			((*param)->width_win - (*param)->width_img) / 2,
			((*param)->height_win - (*param)->height_img) / 2);
}

/*
static void		draw_pic(t_fdf **param)
{
	int				i;

	i = -1;
	while (++i * 4 < (*param)->sizeline * (*param)->height_img)
		(*param)->pic[i] = mlx_get_color_value((*param)->mlx, 0xff0000);
	mlx_put_image_to_window((*param)->mlx,
			(*param)->win, (*param)->img,
			((*param)->width_win - (*param)->width_img) / 2,
			((*param)->height_win - (*param)->height_img) / 2);
}
*/

static int		key_hook(int keycode, t_fdf *param)
{
	param = NULL;
	if (keycode == 53)
		exit(EXIT_SUCCESS);
	return (0);
}

int				main(int ac, char **av)
{
	t_fdf			*param;

	if (ft_parsing(ac, av, &param))
		return (1);
	display_init(&param);
	draw_pic(&param);
	mlx_key_hook(param->win, key_hook, param);
	mlx_loop(param->mlx);
	return (0);
}
