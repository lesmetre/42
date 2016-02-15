/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpressen <mpressen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/10 18:18:04 by mpressen          #+#    #+#             */
/*   Updated: 2016/02/15 09:51:32 by mpressen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include <unistd.h>
# include <fcntl.h>
# include <stdlib.h>
//# include <sys/errno.h> // system calls and error numbers
//# include <stdio.h> // perror
//# include <string.h> // strerror
//# include <math.h>

typedef struct	s_fdf_list
{
	void				*mlx;
	void				*win;
	void				*img;
	int					width_win;
	int					height_win;
	int					width_img;
	int					height_img;
	int					x;
	int					y;
	int					z;
	int					x1;
	int					y1;
	struct s_fdf_list	*next;
}				t_fdf_list;

#endif
