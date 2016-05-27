/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpressen <mpressen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/10 18:18:04 by mpressen          #+#    #+#             */
/*   Updated: 2016/05/27 15:10:55 by mpressen         ###   ########.fr       */
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
# include <pthread.h>

typedef struct	s_fractolparam
{
	char				*fractal;
	void				*mlx;
	double				width;
	double				height;
	void				*win;
	void				*img;
	unsigned int		*pic;
	int					bpp;
	int					sizeline;
	int					endian;
	double				x1;
	double				y1;
	double				x2;
	double				y2;
	double				zoom;
	int					iteration_max;
	double				pixmax;
	double				mousex;
	double				mousey;
	int					movex;
	int					movey;
	double				c_r;
	double				c_i;
	double				z_r;
	double				z_i;
	double				tmp;
	double				c_r2;
	double				c_i2;
	double				z_r2;
	double				z_i2;
	double				tmp2;
	double				c_r3;
	double				c_i3;
	double				z_r3;
	double				z_i3;
	double				tmp3;
	double				c_r4;
	double				c_i4;
	double				z_r4;
	double				z_i4;
	double				tmp4;
	int					block;

}				t_fractolparam;

void			draw_Burning_ship(t_fractolparam *param);
void			draw_Logbrot(t_fractolparam *param);
void			draw_Julia(t_fractolparam *param);
void			draw_Sierpinski_triangle(t_fractolparam *param);
void			draw_Sierpinski_carpet(t_fractolparam *param);
void			draw_Mpressen(t_fractolparam *param);
void			draw_Mandelbar(t_fractolparam *param);
void			draw_Mandelbrot(t_fractolparam *param);
void			draw_Multibar(t_fractolparam *param);
void			draw_Multibrot(t_fractolparam *param);
void			draw_pic(t_fractolparam **param);
void			draw_pixel(int x, int y, t_fractolparam *param, int color); 
int				key_hook(int keycode, t_fractolparam *param);
int				mouse_hook(int button, int x, int y, t_fractolparam *param);
int				julia_hook(int x, int y, t_fractolparam *param);

#endif
