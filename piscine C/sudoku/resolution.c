/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   resolution.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpressen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/23 20:00:59 by mpressen          #+#    #+#             */
/*   Updated: 2015/12/23 23:34:49 by mpressen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sudoku.h"

int		resolution(char **tab, int number_of_9)
{
	int		column;
	int		solutions;

	solutions = 0;
	column = -1;
	if (queens == 8)
	{
		print_tab(tab);
		ft_putchar('\n');
		return (1);
	}
	while (++column < 8)
	{
		if (no_queen_check(queens, column, tab))
		{
			tab[queens][column] = '1';
			solutions += resolution(tab, queens + 1);
			tab[queens][column] = '.';
		}
	}
	return (solutions);
}
