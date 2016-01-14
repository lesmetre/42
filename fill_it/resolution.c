/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   resolution.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpressen <mpressen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/14 06:32:07 by mpressen          #+#    #+#             */
/*   Updated: 2016/01/14 07:38:31 by mpressen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static int		check_free_space(char **tab, char **tetrimino, int line, int column);

static char		**insert_tetrimino(char **tab, char **tetrimino, int line, int column);

static char		**delete_tetrimino(char **tab, char **tetrimino, int line, int column);
	

char			**resolution(char **tab, t_chain list, int tetriminos)
{
	int		tetrimino_to_set;
	int		tetrimino_set;
	int		line;
	int		column;
	char	letter;
	int		i;
	
	i = 0;
	tetrimino_to_set = 0;
	while (!tetrimino_to_set && i < tetrimino)
	{
		tetrimino_set = 0;
		letter = 'A' + i;
		line = -1;
		while (!tetrimino_set && tab[++line])
		{
			column = -1;
			while (!tetrimino_set && tab[line][++column])
				if (tab[line][column] == letter) 
					tetrimino_set = 1;
		}
		if (tetrimino_set)
			i++;
		else
			tetrimino_to_set = 1;
	}
	if (!tetrimino_to_set)
		return (tab);
	while (i--)
		list = list->next;
	line = -1;
	while (tab[++line])
	{
		column = -1;
		while (tab[line][++column])
		{
			if (check_free_space(tab, list->tetrimino, line, column))
			{
				tab = insert_tetrimino(tab, list->tetrimino, line, column);
				if (resolution(tab, list, tetriminos))
					return (resolution(tab, list, tetriminos));
				tab = delete_tetrimino(tab, list->tetrimino, line, column);
			}
		}
	}
	return (NULL);
}
