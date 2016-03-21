/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpressen <mpressen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/12 01:10:10 by mpressen          #+#    #+#             */
/*   Updated: 2016/03/21 06:05:00 by mpressen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void		display_init(t_fdf **param)
{
	(*param)->mlx = mlx_init();
	(*param)->width_win = 1000;
	(*param)->height_win = 500;
	(*param)->win = mlx_new_window((*param)->mlx,
			(*param)->width_win, (*param)->height_win, "FdF");
	(*param)->width_img = 1000;
	(*param)->height_img = 500;
	(*param)->img = mlx_new_image((*param)->mlx,
			(*param)->width_img, (*param)->height_img);
	(*param)->pic = (unsigned int*)mlx_get_data_addr((*param)->img,
			&(*param)->bpp, &(*param)->sizeline, &(*param)->endian);
	ft_putstr("bpp = ");
	ft_putnbr((*param)->bpp);
	ft_putendl(".");
	ft_putstr("sizeline = ");
	ft_putnbr((*param)->sizeline);
	ft_putendl(".");
	ft_putstr("endian = ");
	ft_putnbr((*param)->endian);
	ft_putendl(".");
}

static void		draw_pic(t_fdf **param)
{
	int		i;
	int		center;
	t_fdf	*browser;
	t_fdf	*tmp;

	browser = *param;
	center = (*param)->sizeline / 4 * (*param)->height_win / 2 + (*param)->sizeline / 8;
	while (browser)
	{
		i = center + browser->x1 * 16 + (browser->y1 * (*param)->sizeline * 4) + 0.5; 
		(*param)->pic[i] = mlx_get_color_value((*param)->mlx, 0xff0000);
		tmp = browser->next;
		if (tmp && browser->y == tmp->y)
			draw_line(&param, browser->x, tmp->x);
		while (tmp && browser->x != tmp->x)
			tmp = tmp->next;
		if (tmp)
			draw_line(&param, browser->y, tmp->y);
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
	t_fdf			*param;

	if (ft_parsing(ac, av, &param))
		return (1);
	display_init(&param);
	draw_pic(&param);
	mlx_key_hook(param->win, key_hook, param);
	mlx_loop(param->mlx);
	return (0);
}
