/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpressen <mpressen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/10 18:18:04 by mpressen          #+#    #+#             */
/*   Updated: 2016/02/13 02:51:52 by mpressen         ###   ########.fr       */
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
	int					x;
	int					y;
	int					z;
	struct s_fdf_list	*next;
}				t_fdf_list;

#endif
