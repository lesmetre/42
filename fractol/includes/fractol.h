/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpressen <mpressen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/10 18:18:04 by mpressen          #+#    #+#             */
/*   Updated: 2016/06/03 13:44:12 by mpressen         ###   ########.fr       */
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
	int					imax;
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
	int					color;
	int					mandel;
	int					nbfract;
}				t_fractolparam;

void			draw_burning_ship(t_fractolparam *p);
void			draw_logbrot(t_fractolparam *p);
void			draw_julia(t_fractolparam *p);
void			draw_sierpinski_triangle(t_fractolparam *p);
void			draw_sierpinski_carpet(t_fractolparam *p);
void			draw_mpressen(t_fractolparam *p);
void			draw_mandelbar(t_fractolparam *p);
void			draw_mandelbrot(t_fractolparam *p);
void			draw_multibar(t_fractolparam *p);
void			draw_multibrot(t_fractolparam *p);
void			draw_pic(t_fractolparam **p);
void			choose_color(int x, int y, t_fractolparam *p, int color);
void			draw_pixel(int x, int y, t_fractolparam *p, int color);
int				key_hook(int keycode, t_fractolparam *p);
void			change_fractal(int keycode, t_fractolparam **p);
int				mouse_hook(int button, int x, int y, t_fractolparam *p);
int				julia_hook(int x, int y, t_fractolparam *param);
void			draw_julia1bis(t_fractolparam *p, int x, int y);
void			draw_julia2bis(t_fractolparam *p, int x, int y);
void			draw_julia3bis(t_fractolparam *p, int x, int y);
void			draw_julia4bis(t_fractolparam *p, int x, int y);
void			draw_mpressen1bis(t_fractolparam *p, int x, int y, int i);
void			draw_mpressen2bis(t_fractolparam *p, int x, int y, int i);
void			draw_mpressen3bis(t_fractolparam *p, int x, int y, int i);
void			draw_mpressen4bis(t_fractolparam *p, int x, int y, int i);
void			draw_legend(t_fractolparam *p);
int				expose_hook(t_fractolparam *p);
void			rename_file(t_fractolparam *p);
int				julia_hook(int x, int y, t_fractolparam *p);
void			draw_minimandel(t_fractolparam *p, int x, int y, int i);
void			mouse_hook2(int button, t_fractolparam *p);
void			recon_fractal(t_fractolparam *p);
#endif
