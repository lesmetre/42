/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   no_queen_check.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpressen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/22 14:54:43 by mpressen          #+#    #+#             */
/*   Updated: 2015/12/23 14:49:32 by mpressen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "eight_queens.h"

int     no_queen_line(int line, int column, char **tab)
{
    while (column--)
        if (tab[line][column] == '1')
            return (0);
    return (1);
}

int     no_queen_column(int line, int column, char **tab)
{
    while (line--)
        if (tab[line][column] == '1')
            return (0);
    return (1);
}

int     no_queen_diagonale_left(int line, int column, char **tab)
{
    while (line-- && column--)
        if (tab[line][column] == '1')
            return (0);
    return (1);
}

int     no_queen_diagonale_right(int line, int column, char **tab)
{
    while (line-- && column++ < 7)
        if (tab[line][column] == '1')
            return (0);
    return (1);
}

int     no_queen_check(int line, int column, char **tab)
{
    if (no_queen_line(line, column, tab) &&
        no_queen_column(line, column, tab) &&
        no_queen_diagonale_left(line, column, tab) &&
        no_queen_diagonale_right(line, column, tab))
        return (1);
    return (0);
}
