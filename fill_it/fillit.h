/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpressen <mpressen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/11 10:07:05 by mpressen          #+#    #+#             */
/*   Updated: 2016/01/14 11:40:04 by mpressen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H
# define BUFF_SIZE	1
# include "libft.h"
# include <stdlib.h>
# include <fcntl.h>
# include <unistd.h>

typedef struct		s_chain
{
	struct s_chain	*next;
	char			**tetrimino;
}					t_chain;

int					list_valid(char *str);
int					tetrimino_valid(char *str);
t_chain				*stock_tetriminos(char *str);
void				free_tab(char **str);
void				fillit(t_chain *list);
char				**resolution(char **tab, t_chain *list, int tetriminos);

#endif
