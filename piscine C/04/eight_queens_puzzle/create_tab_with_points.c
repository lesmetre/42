/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_tab_with_points.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpressen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/22 14:52:43 by mpressen          #+#    #+#             */
/*   Updated: 2015/12/22 15:05:06 by mpressen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "eight_queens.h"

char    **create_tab_with_points(void)
{
    char    **tab;
    int     line;
    int     column;

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
