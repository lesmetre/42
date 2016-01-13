/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpressen <mpressen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/11 10:07:05 by mpressen          #+#    #+#             */
/*   Updated: 2016/01/13 02:02:39 by mpressen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H
# define BUFF_SIZE	1
# include "libft.h"
# include <stdlib.h>
# include <fcntl.h>
# include <unistd.h>

typedef struct      s_chain
{
	struct  s_chain *next;
	char			**tetrimino;
}                   t_chain;

int		list_valid(char *str);
int		tetrimino_valid(char *str);
t_chain	*stock_tetriminos(char *str);
t_chain	*create_new_struct(t_chain *list);
void	free_tab(char **str);
//char	**fillit(t_chain *list);

#endif
