/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpressen <mpressen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/11 10:07:48 by mpressen          #+#    #+#             */
/*   Updated: 2016/01/14 04:42:50 by mpressen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static int		count_tetriminos(t_chain *list)
{
	int tetriminos;

	tetriminos = 0;
	while (list)
	{
		tetriminos++;
		list = list->next;
	}
	return (tetriminos);
}

static char		**create_tab(int tetriminos, int more)
{
	char	**tab;
	int		x;
	int		i;
	int		j;

	x = 0;
	i = -1;
	while (x * x < tetriminos * 4)
		x++;
	x += more;
	if (!(tab = (char **)malloc(sizeof(*tab) * x + 1)))
		return (NULL);
	while (++i < x)
	{
		j = -1;
		if (!(tab[i] = (char *)malloc(sizeof(**tab) * x + 1)))
			return (NULL);
		while (++j < x)
		{
			tab[i][j] = '.';
		}
		tab[i][j] = '\0';
	}
	tab[i] = NULL;
	return (tab);
}

char			**fillit(t_chain *list)
{
	int more;

	more = 0;
	return (create_tab(count_tetriminos(list), more));
}
