/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpressen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/23 20:01:37 by mpressen          #+#    #+#             */
/*   Updated: 2015/12/23 23:27:20 by mpressen         ###   ########.fr       */
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
	line = line - (line % 3);
	while (line < line + 3)
	{
		column = column - (column % 3);
		while (column < column + 3)
		{
			if (tab[line][column] == c)
				return (0);
			column++;
		}
		line++;
	}
	return (1);
}

int		check(int line, int column, char c, char **tab)
{
	if (check_line(line, column, c, tab) &&
			check_column(line, column, c, tab) &&
			check_block(line, column, c, tab))
		return (1);
	return (0);
}
