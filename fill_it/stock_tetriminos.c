/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stock_tetriminos.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpressen <mpressen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/12 02:54:36 by mpressen          #+#    #+#             */
/*   Updated: 2016/01/12 07:30:42 by mpressen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

t_chain		*create_new_struct(t_chain *list)
{
	t_chain		*new_struct;
	
	if (!(new_struct = (t_chain*)malloc(sizeof(*new_struct))))
		return (NULL);
	if (list == NULL)
	{
		list = new_struct;
		list->next = NULL;
		list->prev = NULL;
	}
	else
	{
		list->next = new_struct;
		new_struct->next = NULL;
		new_struct->prev = list;
	}
	return (list);
}

t_chain		*stock_tetriminos(char *str)
{
	t_chain		*list;
	t_chain		*begin_list;
	char		*tmp;
	int			i;

	i = 0;
	list = NULL;
	tmp = NULL;
	list = create_new_struct(list);
	begin_list = list;
	while (list)
	{
		if (!(tmp = (char *)malloc(sizeof(*tmp) * 21)))
			return (NULL);
		tmp[20] = '\0';
		tmp[0] = str[i];
		while (++i % 20)
			tmp[i % 20] = str[i];
		list->tetrimino = ft_strsplit(tmp, '\n');
		if (str[i])
			list = create_new_struct(list);
		list = list->next;
		free(tmp);
	}
	return (begin_list);
}

/*	t_chain		*tetriminos;
	int			i;
	int			j;
	int			count_blocks;
	char		**split;

	tetriminos = NULL;
	create_new_struct(tetriminos);
	tetriminos->tab[0]->i = 0;
	tetriminos->tab[0]->j = 0;
	i = 0;
	if (!(split = ft_strsplit(str, '\n')))
		return (NULL);
	while (tetriminos)
	{
		count_blocks = -1;
		while (++count_blocks < 4)
		{
			j = -1;
			while (split[i][++j])
			{
				if (split[i][j] = '#' && count_blocks == 0)
				{
					
					
				}
				else if (split[i][j] = '#' && count_blocks != 0)
				{
					tetriminos->tab[count_blocks]->i = ;
					tetriminos->tab[count_blocks]->j = ;
				}	
			}
			i++;
		}
		count_tetriminos++;
		if (str[i + 4])
			create_new_struct(tetriminos);
		tetriminos = tetriminos->next;	
	}
	
	
	return (tetriminos);
	}*/
