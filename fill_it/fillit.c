/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpressen <mpressen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/11 10:07:48 by mpressen          #+#    #+#             */
/*   Updated: 2016/01/14 13:04:21 by mpressen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static int		count_tetriminos(t_chain *list)
{
	int tetriminos;

	ft_putendl("on rentre dans count_tetriminos");
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

	ft_putendl("on rentre dans create_tab");
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

static void		print_tab(char **tab)
{
	int i;
	int j;

	ft_putendl("on rentre dans print_tab");
	i = -1;
	while (tab[++i])
	{
		j = -1;
		while (tab[i][++j])
			ft_putchar(tab[i][j]);
		ft_putchar('\n');
	}
}

void			fillit(t_chain *list)
{
	char	**tab;
	int		more;
	char	**solution;
	int		tetriminos;

	ft_putendl("on rentre dans fillit");
	tab = NULL;
	solution = NULL;
	more = 0;
	tetriminos = count_tetriminos(list);
	while (!(solution))
	{
		ft_putendl("on rentre dans la boucle du fillit");
		ft_putstr("more a la valeur de ");
		ft_putnbr(more);
		ft_putstr(".\n");
		tab = create_tab(tetriminos, more);
		if ((solution = resolution(tab, list, tetriminos)))
			print_tab(solution);
		else
		{
			free_tab(tab);
			more++;
		}
	}
}
	
