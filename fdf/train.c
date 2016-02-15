/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   train.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpressen <mpressen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/12 01:10:10 by mpressen          #+#    #+#             */
/*   Updated: 2016/02/15 09:51:30 by mpressen         ###   ########.fr       */
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
	t_fdf_list		param;
	unsigned int	*pic;
	int				bpp;
	int				sizeline;
	int				endian;
	int				i;

	param.mlx = mlx_init();
	param.width_win = 1000;
	param.height_win = 1000;
	param.win = mlx_new_window(param.mlx, param.width_win, param.height_win, "train fdf");
	param.width_img = 150;
	param.height_img = 150;
	param.img = mlx_new_image(param.mlx, param.width_img, param.height_img);
	pic = (unsigned int*)mlx_get_data_addr(param.img, &bpp, &sizeline, &endian);
	i = -1;
	while (++i * 4 < sizeline * param.height_img)
		pic[i] = mlx_get_color_value(param.mlx, 0xff0000);
	mlx_put_image_to_window(param.mlx, param.win, param.img, (param.width_win - param.width_img) / 2, (param.height_win - param.height_img) / 2);
	mlx_key_hook(param.win, key_hook, &param);
	mlx_loop(param.mlx);
	return (0);
}
