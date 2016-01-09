/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpressen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/31 00:21:08 by mpressen          #+#    #+#             */
/*   Updated: 2016/01/09 07:23:10 by mpressen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# define BUFF_SIZE	1
# define BUFF_SIZE2	2
# define BUFF_SIZE3	3
# define BUFF_SIZE4	5
# define BUFF_SIZE5	7
# define BUFF_SIZE6	9
# define BUFF_SIZE7	11
# define BUFF_SIZE8	13
# define BUFF_SIZE9	66

typedef struct	s_struct
{
	int				fd;
	char			**split;
	int				i;
	struct s_struct	*prev;
	struct s_struct	*next;
}					t_struct;

int				get_next_line(int const fd, char **line);
void			free_tab(char **tab);

#endif
