/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_eight_queens_puzzle_2.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpressen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/27 18:58:39 by mpressen          #+#    #+#             */
/*   Updated: 2015/12/21 23:36:25 by mpressen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

char	**create_tab_with_points(void)
{
	char	**tab;
	int		line;
	int		column;

	line = -1;
	tab = (char **)malloc(sizeof(*tab) * 9);
	while (++line < 8)
	{
		tab[line] = (char *)malloc(sizeof(**tab) * 9);
		column = -1;
		while (++column < 8)
			tab[line][column] = '.';
		tab[line][column] = '\0';
	}
	tab[8] = (char *)malloc(sizeof(**tab));
	tab[8][0] = '\0';
	return (tab);
}

void	print_tab(char **tab)
{
	int		l;
	int		c;

	l = -1;
	while (tab[++l])
	{
		c = -1;
		while (tab[l][++c])
			ft_putchar(tab[l][c]);
		ft_putchar('\n');
	}
}

int		no_queen_line(int line, int column, char **tab)
{
	while (column >= 0)
	{
		if (tab[line][column] == '1')
			return (0);
		column--;
	}
	return (1);
}

int		no_queen_column(int line, int column, char **tab)
{
	while (line >= 0)
	{
		if (tab[line][column] == '1')
			return (0);
		line--;
	}
	return (1);
}

int		no_queen_diagonale_left(int line, int column, char **tab)
{
	while (line >= 0 && column >= 0)
	{
		if (tab[line][column] == '1')
			return (0);
		line--;
		column--;
	}
	return (1);
}

int		no_queen_diagonale_right(int line, int column, char **tab)
{
	while (line >= 0 && column < 8)
	{
		if (tab[line][column] == '1')
			return (0);
		line--;
		column++;
	}
	return (1);
}

void	resolution(char **tab, int queens)
{
	int line;
	int column;

	line = -1;
	if (queens == 8)
	{
		print_tab(tab);
	}
	else
		while (tab[++line])
		{
			column = -1;
			while (tab[line][++column])
				if (no_queen_line(line, column, tab) && no_queen_column(line, column, tab) && no_queen_diagonale_left(line, column, tab) && no_queen_diagonale_right(line, column, tab))
				{
					tab[line][column] = '1';
					resolution(tab, queens++);
					if (column == 7)
						line = 7;
					else
						tab[line][column] = '.';	
				}
		}
}

int		main(void)
{
	resolution(create_tab_with_points(), 0);
	return (0);
}
