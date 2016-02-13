/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   train.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpressen <mpressen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/12 01:10:10 by mpressen          #+#    #+#             */
/*   Updated: 2016/02/13 08:56:00 by mpressen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include "fdf.h"
#include <unistd.h>
#include "libft.h"

int		key_hook(int keycode, t_fdf_list *param)
{
	if (keycode == 53)
		exit(EXIT_SUCCESS);
	return (0);
}

int		main(void)
{
	t_fdf_list	*param;
	char		*pic;
	int			bpp;
	int			width;
	int			height;
	int			size_line;
	int			endian;
	int			i;
	char		*tmp;

	width = 10;
	height = 10;
	size_line = 4 * width;
	bpp = 4;
	endian = 0;
	param->mlx = mlx_init();
	param->win = mlx_new_window(param->mlx, 400, 400, "train fdf");
	param->img = mlx_new_image(param->mlx, width, height);
	pic = mlx_get_data_addr(param->img, &bpp, &size_line, &endian);
	tmp = pic;
	print_memory(pic, size_line * height);
	while (height--)
	{
		i = -1;
		while (++i < size_line)
		{
//			pic[i] = 0x00;
//			pic[++i] = 0x00;
//			pic[++i] = 0xff;
//			pic[++i] = 0x00;
		}
		pic = pic + size_line;
	}
	pic = tmp;
	ft_putendl("-------------------------");
	print_memory(pic, size_line * 10);
	mlx_put_image_to_window(param->mlx, param->win, param->img, 190, 190);
	mlx_key_hook(param->win, key_hook, (void*)param);
	mlx_loop(param->mlx);
	return (0);
}

// (char)mlx_get_color_value(param->mlx, 0xffffff);
