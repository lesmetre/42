/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpressen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/27 18:58:39 by mpressen          #+#    #+#             */
/*   Updated: 2015/12/23 19:51:54 by mpressen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "eight_queens.h"
#include <stdio.h>

int		main(void)
{
	char	**tab;
	int		line;
	int		column;

	if ((tab = (char **)malloc(sizeof(*tab) * 9)))
	{
		line = -1;
		while (++line < 8)
		{
			if ((tab[line] = (char *)malloc(sizeof(**tab) * 9)))
			{
				column = -1;
				while (++column < 8)
					tab[line][column] = '.';
				tab[line][column] = '\0';
			}
			else
				tab[line] = NULL;
		}
		tab[line] = 0;
	}
	printf("Il y a %d solutions !\n", resolution(tab, 0));
	return (0);
}
