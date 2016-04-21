/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpressen <mpressen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/10 18:18:04 by mpressen          #+#    #+#             */
/*   Updated: 2016/04/21 20:59:17 by mpressen         ###   ########.fr       */
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

typedef struct	s_fdfparse
{
	char	**tab;
	int		*int_tab;
	int		*color;
}				t_fdfparse;

typedef struct	s_fdflist
{
	int					x;
	int					y;
	int					z;
	int					color;
	struct s_fdflist	*next;
}				t_fdflist;

typedef struct	s_fdfparam
{
	char				*file;
	int					width;
	int					height;
	void				*mlx;
	void				*win;
	void				*img;
	unsigned int		*pic;
	int					bpp;
	int					sizeline;
	int					endian;
	int					midwidth;
	int					midheight;
	double				x1;
	double				x2;
	double				y1;
	double				y2;
	double				modx;
	double				mody;
	double				modz;
	int					zoom;
	int					pixmax;
	t_fdflist			*list;
}				t_fdfparam;

int				ft_parsing(int ac, char **av, t_fdflist **list);
void			draw_pic(t_fdflist *list, t_fdfparam *param);
int				key_hook(int keycode, t_fdfparam *param);
int				ft_atoi_hexa(const char *str);
int				ft_error(int error, char *str);
#endif
