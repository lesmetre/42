/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpressen <mpressen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/10 18:18:04 by mpressen          #+#    #+#             */
/*   Updated: 2016/04/23 23:14:22 by mpressen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H
# include "mlx.h"
# include "libft.h"
# include <unistd.h>
# include <fcntl.h>
# include <stdlib.h>
# include <math.h>

typedef struct	s_fractolparam
{
	char				*fractal;
	void				*mlx;
	void				*win;
	void				*img;
	unsigned int		*pic;
	int					bpp;
	int					sizeline;
	int					endian;
	double				x1;
	double				x2;
	double				y1;
	double				y2;
	double				zoom;
	int					iteration_max;
	int					image_x;
	int					image_y;
	int					**pixeltab;
}				t_fractolparam;

void			draw_pic(t_fractolparam *param);
int				key_hook(int keycode, t_fractolparam *param);
#endif
