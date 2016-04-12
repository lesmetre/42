/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpressen <mpressen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/12 01:10:10 by mpressen          #+#    #+#             */
/*   Updated: 2016/04/13 00:59:35 by mpressen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void		display(t_fdfparam **addr_param, char *file)
{
	t_fdfparam	*param;

	if (!(param = (t_fdfparam*)malloc(sizeof(*param))))
    {
        ft_error_malloc("display");
        exit(1);
    }

	param->width = 1920;
	param->height = 1080; 
	param->mlx = mlx_init();
	param->win = mlx_new_window(param->mlx, param->width, param->height, file);
	param->img = mlx_new_image(param->mlx, param->width, param->height);
	param->pic = (unsigned int *)mlx_get_data_addr
		(param->img, &param->bpp, &param->sizeline, &param->endian);
	param->center = param->width / 2 + param->height / 2 * param->width;
	*addr_param = param;
}

static int		key_hook(int keycode, t_fdfparam *param)
{
	if (keycode == 53 || keycode == 12)
		exit(EXIT_SUCCESS);
	param = NULL;
	return (0);
}

int				main(int ac, char **av)
{
	t_fdfparam			*param;
	t_fdflist			*list;

	list = NULL;
	param = NULL;
	if (ft_parsing(ac, av, &list))
		return (1);
	display(&param, av[1]);
	draw_pic(list, param);
	mlx_key_hook(param->win, key_hook, param);
	mlx_loop(param->mlx);
	return (0);
}
