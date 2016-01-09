/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpressen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/31 00:21:08 by mpressen          #+#    #+#             */
/*   Updated: 2016/01/09 02:47:01 by mpressen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# define BUFF_SIZE	11

typedef struct	s_struct
{
	char		**split;
	int			i;
}				t_struct;

int				get_next_line(int const fd, char **line);
void			free_tab(char **tab);

#endif
