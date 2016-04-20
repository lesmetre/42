/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpressen <mpressen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/12 01:10:10 by mpressen          #+#    #+#             */
/*   Updated: 2016/04/20 17:39:43 by mpressen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void		display(t_fdfparam **addr_param, char *file, t_fdflist *list)
{
	t_fdfparam	*param;

	if (!(param = (t_fdfparam*)malloc(sizeof(*param))))
	{
		ft_error_malloc("display");
		exit(1);
	}
	param->width = 2560;
	param->height = 1440;
	param->mlx = mlx_init();
	param->win = mlx_new_window(param->mlx,
		param->width, param->height, ft_strrchr(file, '/') + 1);
	param->img = mlx_new_image(param->mlx, param->width, param->height);
	param->pic = (unsigned int *)mlx_get_data_addr(param->img,
		&param->bpp, &param->sizeline, &param->endian);
	param->center = param->width / 2 + param->height / 2 * param->width;
	param->zoom = 1;
	param->list = list;
	param->pixmax = param->width * param->height;
	param->modx = 1;
	param->mody = 1;
	param->modz = 1;
	*addr_param = param;
}

int				main(int ac, char **av)
{
	t_fdfparam			*param;
	t_fdflist			*list;

	list = NULL;
	param = NULL;
	if (ft_parsing(ac, av, &list))
		return (1);
	display(&param, av[1], list);
	draw_pic(list, param);
	mlx_key_hook(param->win, key_hook, param);
	mlx_loop(param->mlx);
	return (0);
}
