/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpressen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/23 20:01:37 by mpressen          #+#    #+#             */
/*   Updated: 2015/12/28 23:01:07 by mpressen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sudoku.h"

int		check_line(int line, int column, char c, char **tab)
{
	while (column--)
		if (tab[line][column] == c)
			return (0);
	return (1);
}

int		check_column(int line, int column, char c, char **tab)
{
	while (line--)
		if (tab[line][column] == c)
			return (0);
	return (1);
}

int		check_block(int line, int column, char c, char **tab)
{
	int i;
	int j;

	i = 0;
	line = line - (line % 3);
	column = column - (column % 3);
	while (i < 3)
	{
		j = 0;
		while (j < 3)
		{
			if (tab[line][column] == c)
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int		check_emptycase(int line, int column, char **tab)
{
	if (tab[line][column] != '.')
		return (0);
	return (1);
}

int		check(int line, int column, char c, char **tab)
{
	if (check_line(line, column, c, tab) && check_column(line, column, c, tab) && check_block(line, column, c, tab))
		return (1);
	return (0);
}
