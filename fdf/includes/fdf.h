/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpressen <mpressen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/10 18:18:04 by mpressen          #+#    #+#             */
/*   Updated: 2016/04/12 01:48:57 by mpressen         ###   ########.fr       */
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

typedef struct			s_fdfparam
{
	int					width;
	int					height;
	void				*mlx;
	void				*win;
	void				*img;
	unsigned int		*pic;
	int					bpp;
	int					sizeline;
	int					endian;
	int					center;
//	s_fdflist			list;
}						t_fdfparam;

typedef struct			s_fdflist
{
	int					x;
	int					y;
	int					z;
	struct s_fdflist	*next;
}						t_fdflist;


int				ft_parsing(int ac, char **av, t_fdflist **list);
void			draw_pic(t_fdflist *list, t_fdfparam *param);
#endif










