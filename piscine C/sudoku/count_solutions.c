/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   count_solutions.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpressen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/23 20:00:59 by mpressen          #+#    #+#             */
/*   Updated: 2015/12/29 02:02:15 by mpressen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sudoku.h"

int		count_solutions(char **tab)
{
	int		line;
	int		column;
	int		case_to_fill;
	char	c;
	int		solutions;	

	solutions = 0;
	case_to_fill = 0;
	line = -1;
	c = '0';
	while (case_to_fill == 0 && tab[++line])
	{
		column = -1;
		while (case_to_fill == 0 && tab[line][++column])
		{
			if (check_emptycase(line, column, tab))
				case_to_fill = 1;
		}
	}
	if (case_to_fill == 1)
	{
		while (++c <= '9')
		{
			if (check(line, column, c, tab))
			{
				tab[line][column] = c;
				solutions += count_solutions(tab);
				tab[line][column] = '.';
			}
		}
		return (solutions);
	}
	return (1);
}
