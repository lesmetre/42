/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   resolution.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpressen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/22 14:55:28 by mpressen          #+#    #+#             */
/*   Updated: 2015/12/28 19:33:28 by mpressen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "eight_queens.h"

int		resolution(char **tab, int queens)
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
//	free_tab(tab);
	return (solutions);
}
