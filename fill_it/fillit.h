/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpressen <mpressen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/11 10:07:05 by mpressen          #+#    #+#             */
/*   Updated: 2016/01/22 19:06:32 by mpressen         ###   ########.fr       */
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
void				free_tab(char **square);
void				fillit(t_chain *list);
int					resolution(char ***addr_square, t_chain *list, int tetriminos);
void				free_list(t_chain **add_list);
void				print_list(t_chain *list);
void				print_tab(char **square);
void				create_square(char ***addr_square, int size);
void				erase_tetrimino(char ***addr_square, char letter);
int					insert_tetrimino(char ***addr_square, char **tetrimino, int line, int column);

#endif
