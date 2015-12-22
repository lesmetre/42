/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   resolution.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpressen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/22 14:55:28 by mpressen          #+#    #+#             */
/*   Updated: 2015/12/22 16:36:02 by mpressen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "eight_queens.h"

void    resolution(char **tab, int queens)
{
    int column;

	column = -1;
	if (queens == 8)				//condition d'arret
	{
		print_tab(tab);
		free_tab(tab);
		return;
	}
	while (++column < 8)			//resolution
	{
		if (no_queen_check(queens, column, tab))
		{
			tab[queens][column] = '1';
			resolution(tab, ++queens);
			free_tab(tab);
			return;
		}
	}
	while (--queens >= 0)			//backtracking
	{
		column = 8;
		while (--column >= 0)
			if (tab[queens][column] == '1')
			{
				tab[queens][column] = '.';
				while (++column < 8)
					if (no_queen_check(queens, column, tab))
					{
						tab[queens][column] = '1';
						resolution(tab, ++queens);
						free_tab(tab);
						return;
					}
				column = 0;
			}
	}
	free_tab(tab);
}
