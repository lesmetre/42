/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stock_tetriminos.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpressen <mpressen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/12 02:54:36 by mpressen          #+#    #+#             */
/*   Updated: 2016/01/13 02:49:34 by mpressen         ###   ########.fr       */
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
	}
	else
	{
		list->next = new_struct;
		new_struct->next = NULL;
	}
	return (list);
}

t_chain		*stock_tetriminos(char *str)
{
	t_chain		*list;
	t_chain		*begin_list;
	char		*tmp;
	int			i;
	int			tetriminos;

	i = 0;
	list = NULL;
	tmp = NULL;
	tetriminos = 1;
	list = create_new_struct(list);
	begin_list = list;
	while (list)
	{
		if (!(tmp = (char *)malloc(sizeof(*tmp) * 22)))
			return (NULL);
		tmp[21] = '\0';
		if (str[i] == '#')
			tmp[0] = '@' + tetriminos;
		else
			tmp[0] = str[i];
		while (++i % 21)
		{
			if (str[i] == '#')
				tmp[i % 21] = '@' + tetriminos;
			else
				tmp[i % 21] = str[i];
		}
		list->tetrimino = ft_strsplit(tmp, '\n');
		free(tmp);
		if (str[i] && str[i + 1])
		{
			tetriminos++;
			list = create_new_struct(list);
		}
		list = list->next;
	}
	return (begin_list);
}
