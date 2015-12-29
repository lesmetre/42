/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpressen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/23 20:01:13 by mpressen          #+#    #+#             */
/*   Updated: 2015/12/29 01:58:54 by mpressen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sudoku.h"
#include <stdio.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	print_tab(char **tab)
{
	int	l;
	int	c;

	l = -1;
	while (tab[++l])
	{
		c = -1;
		while (tab[l][++c])
		{
			ft_putchar(tab[l][c]);
			if (c < 8)
				ft_putchar(' ');
			else
				ft_putchar('\n');
		}
	}
}

int		valid_grid(int ac, char **av)
{
	int		column;

	while (--ac)
	{
		column = 0;
		while ((av[ac][column] >= '0' && av[ac][column] <= '9') || av[ac][column] == '.')
			column++;
		if (column != 9)
			return (0);
	}
	return (1);
}

char	**create_tab(int ac, char **av)
{
	char	**tab;
	int		line;
	int		column;

	tab = NULL;
	if ((tab = (char **)malloc(sizeof(*tab) * 10)))
	{
		line = -1;
		while (++line < (ac - 1))
		{
			if ((tab[line] = (char *)malloc(sizeof(**tab) * 10)))
			{
				column = -1;
				while (++column < 9)
					tab[line][column] = av[line + 1][column];
				tab[line][column] = '\0';
			}
			else
				tab[line] = NULL;
		}
		tab[line] = 0;
	}
	return (tab);
}

int		main(int ac, char **av)
{
	if (ac != 10 || !(valid_grid(ac, av)))
	{
		printf("Erreur\n");
		return (0);
	}
	if (count_solutions(create_tab(ac, av)) == 1)
		resolution(create_tab(ac, av));
	else
		printf("Erreur\n");
	return (0);
}
