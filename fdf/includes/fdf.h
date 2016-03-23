/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpressen <mpressen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/10 18:18:04 by mpressen          #+#    #+#             */
/*   Updated: 2016/03/23 14:10:09 by mpressen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H
# include "mlx.h"
# include "libft.h"
# include <unistd.h>
# include <fcntl.h>
# include <stdlib.h>
# include <math.h>

typedef struct	s_fdf
{
	void			*mlx;
	void			*win;
	void			*img;
	int				width_win;
	int				height_win;
	int				width_img;
	int				height_img;
	unsigned int	*pic;
	int				bpp;
	int				sizeline;
	int				endian;
	int				x;
	int				y;
	int				z;
	double			x1;
	double			y1;
	int				x2;
	int				y2;
	int				x3;
	int				y3;
	struct s_fdf	*next;
}				t_fdf;

int				ft_parsing(int ac, char **av, t_fdf **param);
void			draw_line(int x1, int x2, int y1, int y2);
#endif










