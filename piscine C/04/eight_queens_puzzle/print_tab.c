/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_tab.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpressen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/22 14:53:08 by mpressen          #+#    #+#             */
/*   Updated: 2015/12/23 14:32:29 by mpressen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "eight_queens.h"

void    ft_putchar(char c)
{
    write(1, &c, 1);
}

void    print_tab(char **tab)
{
    int     l;
    int     c;

    l = -1;
    while (tab[++l])
    {
        c = -1;
        while (tab[l][++c])
		{
            ft_putchar(tab[l][c]);
            ft_putchar(' ');
		}
        ft_putchar('\n');
    }
}
