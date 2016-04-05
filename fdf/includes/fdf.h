/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpressen <mpressen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/10 18:18:04 by mpressen          #+#    #+#             */
/*   Updated: 2016/04/05 20:59:36 by mpressen         ###   ########.fr       */
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
	unsigned int	*pic;
	int				bpp;
	int				sizeline;
	int				endian;
	int				center;
	int				x;
	int				y;
	int				z;
	float			x1;
	float			y1;
	struct s_fdf	*next;
}				t_fdf;

int				ft_parsing(int ac, char **av, t_fdf **param);
void			draw_pic(t_fdf param);
#endif










