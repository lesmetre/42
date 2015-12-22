/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   resolution.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpressen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/22 14:55:28 by mpressen          #+#    #+#             */
/*   Updated: 2015/12/22 15:07:09 by mpressen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "eight_queens.h"

char    **backtracking(char **tab)
{
    int line;
    int column;

    line = 7;
    while (line--)
    {
        column = 8;
        while (column--)
            if (tab[line][column] == '1')
            {
                tab[line][column] = '.';
                while (++column < 8)
                    if (no_queen_check(line, column, tab))
                    {
                        tab[line][column] = '1';
                        return(tab);
                    }
            }
    }
    free_tab(tab);
    return (NULL);
}

void    resolution(char **tab, int queens)
{
    int line;
    int column;
    int queen_on_line;

    line = -1;
    if (queens == 8)
    {
        print_tab(tab);
        free_tab(tab);
    }
    else
        while (tab[++line])
        {
            queen_on_line = 0;
            column = -1;
            while (tab[line][++column])
            {
                if (tab[line][column] == '1')
                {
                    column = 7;
                    queen_on_line = 1;
                }
                else if (no_queen_check(line, column, tab))
                {
                    tab[line][column] = '1';
                    queen_on_line = 1;
                    resolution(tab, ++queens);
                    free_tab(tab);
                    column = 7;
                    line = 7;

                }
            }
            if (queen_on_line == 0)
            {
                resolution(backtracking(tab), --queens);
                free_tab(tab);
                line = 7;
			}
        }
}
