/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   resolution.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpressen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/22 14:55:28 by mpressen          #+#    #+#             */
/*   Updated: 2015/12/23 19:30:51 by mpressen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "eight_queens.h"
#include <stdio.h>

int    resolution(char **tab, int queens)
{
    int		column;
//	int		queen_on_line;
	int		solutions;

	solutions = 0;
	column = -1;
	if (queens == 8)				//condition d'arret
	{
		print_tab(tab);
		solutions++;
		ft_putchar('\n');
		return (solutions);
	}
    while (++column < 8)            //resolution complexe
    {
        if (no_queen_check(queens, column, tab))
        {
           tab[queens][column] = '1';
//			queen_on_line = 1;
            solutions += resolution(tab, queens + 1);
            tab[queens][column] = '.';
        }
    }
/*	if (!(queen_on_line))
	{
		while (--queens)			//backtracking
		{
			column = 8;
			while (column--)
			{
				if (tab[queens][column] == '1')
				{
					tab[queens][column] = '.';
					while (++column < 8)
						if (no_queen_check(queens, column, tab))
						{
							tab[queens][column] = '1';
							solutions += resolution(tab, queens + 1);
						}
					column = 0;
				}
			}
		}
		}*/
	return(solutions);
}
