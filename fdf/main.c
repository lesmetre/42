/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpressen <mpressen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/12 01:10:10 by mpressen          #+#    #+#             */
/*   Updated: 2016/04/05 20:59:41 by mpressen         ###   ########.fr       */
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
	param->pic = (unsigned int *)mlx_get_data_addr
		(param->img, &param->bpp, &param->sizeline, &param->endian);
	param->sizeline /= 4;
	param->center = param->sizeline * height / 2 + param->sizeline / 2;
}

static int		key_hook(int keycode, t_fdf *param)
{
	param = NULL;
	if (keycode == 53)
		exit(EXIT_SUCCESS);
	return (0);
}

static void		show_list(t_fdf *param)
{
	int i;

	i = 0;
	while (param)
	{
		i++;
		param = param->next;
	}
	ft_putstr("Il y a ");
	ft_putnbr(i);
	ft_putendl(" instances dans la liste.");
}

int				main(int ac, char **av)
{
	t_fdf			*param;

	if (ft_parsing(ac, av, &param))
		return (1);
	display_init(&param);
	show_list(&param);
	draw_pic(param);
	mlx_key_hook(param.win, key_hook, &param);
	mlx_loop(param.mlx);
	return (0);
}
