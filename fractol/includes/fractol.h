/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpressen <mpressen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/10 18:18:04 by mpressen          #+#    #+#             */
/*   Updated: 2016/05/05 11:14:43 by mpressen         ###   ########.fr       */
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
	int					width;
	int					height;
	void				*mlx;
	void				*win;
	void				*img;
	unsigned int		*pic;
	int					bpp;
	int					sizeline;
	int					endian;
	double				zoom;
	double				x1;
	double				x2;
	double				y1;
	double				y2;
	int					iteration_max;
	int					image_x;
	int					image_y;
	double				pixmax;
	double				mousex;
	double				mousey;
}				t_fractolparam;

void			init_Burning_ship(t_fractolparam **addr_param);
void			init_Julia(t_fractolparam **addr_param);
void			init_Mandelbar(t_fractolparam **addr_param);
void			init_Mandelbrot(t_fractolparam **addr_param);
void			init_Multibar(t_fractolparam **addr_param);
void			init_Multibrot(t_fractolparam **addr_param);
void			init_Sierpinski_triangle(t_fractolparam **addr_param);
void			init_Sierpinski_carpet(t_fractolparam **addr_param);
void			draw_Burning_ship(t_fractolparam *param, int x, int y, int i);
void			draw_Julia(t_fractolparam *param, int x, int y, int i);
void			draw_Mandelbar(t_fractolparam *param, int x, int y, int i);
void			draw_Mandelbrot(t_fractolparam *param, int x, int y, int i);
void			draw_Multibar(t_fractolparam *param, int x, int y, int i);
void			draw_Multibrot(t_fractolparam *param, int x, int y, int i);
void			draw_Sierpinski_triangle(t_fractolparam *param);
void			draw_Sierpinski_carpet(t_fractolparam *param);
void			draw_pic(t_fractolparam **param);
void			draw_pixel(int x, int y, t_fractolparam *param, int color); 
int				key_hook(int keycode, t_fractolparam *param);
int				mouse_hook(int button, int x, int y, t_fractolparam *param);
int				julia_hook(int x, int y, t_fractolparam *param);
void			draw_miniMandelbrot(t_fractolparam *param, int x, int y, int i);

#endif
