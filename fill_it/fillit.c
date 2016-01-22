/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpressen <mpressen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/11 10:07:48 by mpressen          #+#    #+#             */
/*   Updated: 2016/01/22 19:36:47 by mpressen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static int		count_tetriminos(t_chain *list)
{
	int tetriminos;

	tetriminos = 0;
	while (list)
	{
		tetriminos++;
		list = list->next;
	}
	return (tetriminos);
}

void			create_square(char ***addr_square, int size)
{
	int		i;
	int		j;
	int		stop;

	stop = 0;
	if (!(*addr_square = (char **)malloc(sizeof(**addr_square) * (size + 1))))
	{
		ft_error_malloc("create_square");
		stop = 1;
	}
	(*addr_square)[size] = NULL;
	i = -1;
	while (!stop && ++i < size)
	{
		j = -1;
		if (!((*addr_square)[i] = ft_memalloc(size + 1)))
		{
			ft_error_malloc("create_square");
			stop = 1;
		}
		while (!stop && ++j < size)
			(*addr_square)[i][j] = '.';
	}
}

void			fillit(t_chain *list)
{
	char	**square;
	int		size;
	int		solution;
	int		tetriminos;
	
	solution = 0;
	size = 1;
	tetriminos = count_tetriminos(list);
	while (size * size < tetriminos * 4)
		size++;
	while (!solution)
	{
		create_square(&square, size);
		if (resolution(&square, list, tetriminos))
		{
			solution = 1;
			print_tab(square);
//			free_tab(square);
		}
		else
		{
			size++;
//			free_tab(square);
		}
	}
}
