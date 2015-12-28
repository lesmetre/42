/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpressen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/23 20:01:37 by mpressen          #+#    #+#             */
/*   Updated: 2015/12/28 22:55:47 by mpressen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sudoku.h"
# include <stdio.h>

int		check_line(int line, int column, char c, char **tab)
{
	while (column--)
		if (tab[line][column] == c)
		{
			printf("%c deja dans la ligne %d\n", c, line);
			return (0);
		}
	printf("pas de %c dans la ligne %d\n", c, line);
	return (1);
}

int		check_column(int line, int column, char c, char **tab)
{
	while (line--)
		if (tab[line][column] == c)
		{
			printf("%c deja dans la colonne\n", c);
			return (0);
		}
	printf("pas de %c dans la colonne %d\n", c, column);
	return (1);
}

int		check_block(int line, int column, char c, char **tab)
{
	int i;
	int j;

	i = 0;
	line = line - (line % 3);
	while (i < 3)
	{
		printf("check de la ligne %d\n", line + i);
		column = column - (column % 3);
		j = 0;
		while (j < 3)
		{
			printf("check de la colonne %d sur la ligne %d\n", column + j, line + i);
			if (tab[line][column] == c)
			{
				printf("%c deja dans le block\n", c);
				return (0);
			}
			j++;
		}
		i++;
	}
	printf("pas de %c dans le block\n", c);
	return (1);
}

int		check_emptycase(int line, int column, char **tab)
{
	if (tab[line][column] != '.')
		return (0);
	printf("la case de la ligne %d et de la colonne %d est vide\n", line, column);
	return (1);
}

int		check(int line, int column, char c, char **tab)
{
	if (check_line(line, column, c, tab) && check_column(line, column, c, tab) && check_block(line, column, c, tab))
	{
		printf("on peut placer %c a la ligne %d et a la colonne %d\n", c, line, column);
		return (1);
	}
	return (0);
}
