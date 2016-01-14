/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   resolution.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpressen <mpressen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/14 06:32:07 by mpressen          #+#    #+#             */
/*   Updated: 2016/01/14 16:37:49 by mpressen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static char		**insert_tetrimino(char **tab, char **tetrimino, int line, int column)
{
	int i;
	int j;
	int start_line;
	int start_column;
	int block_placed;
	int stop;
	int x;

	ft_putendl("on rentre dans insert_tetrimino");
	i = -1;
	block_placed = 0;
	stop = 0;
	if(tab[line][column] != '.')
		return (NULL);
	while (!stop && ++i < 4)
	{
		j = -1;
		while(!stop && ++j < 4)
		{
			if (tetrimino[i][j] != '.')
			{
				start_line = i;
				start_column = j;
				stop = 1;
			}		
		}
	}
	stop = 0;
	x = 0;
	while (tab[0][x])
		x++;
	while (!stop && i < 4)
	{
		ft_putendl("on rentre dans la boucle pour placer les blocks");
		ft_putstr("la valeur de i est ");
		ft_putnbr(i);
		ft_putstr(".\n");
		j = -1;
		while (!stop && ++j < 4)
		{
			ft_putstr("la valeur de j est ");
			ft_putnbr(j);
			ft_putstr(".\n");
			if (tetrimino[i][j] != '.')
			{
				ft_putstr("on a identifie un block du tetrimino");
				if (line + i - start_line >= 0 && column + j - start_column >= 0 && line + i - start_line < x && column + j - start_column < x && tab[line + i - start_line][column + j - start_column] == '.')
				{
					ft_putendl(" et on peut le placer dans la grille de solution");
					tab[line + i - start_line][column + j - start_column] = tetrimino[i][j];
					block_placed++;
					if (block_placed == 4)
					{
						ft_putendl("on a place le tetrimino sur la grille de solution");
						return (tab);
					}
				}
				else
				{
					ft_putendl(" mais on ne peut pas le placer dans la grille");
					stop = 1;
				}
			}
		}
		i++;
	}
	ft_putendl("on a pas pu placer le tetrimino");
	return (NULL);
}

char			**resolution(char **tab, t_chain *list, int tetriminos)
{
	int		tetrimino_to_set;
	int		tetrimino_set;
	int		line;
	int		column;
	char	letter;
	int		i;
	char	**tmp;

	ft_putendl("on rentre dans resolution");
	i = 0;
	tetrimino_to_set = 0;
	tmp = tab;
	while (!tetrimino_to_set && i < tetriminos)
	{
		ft_putendl("on check s'il y a un tetrimino a placer");
		tetrimino_set = 0;
		letter = 'A' + i;
		line = -1;
		while (!tetrimino_set && tab[++line])
		{
			column = -1;
			while (!tetrimino_set && tab[line][++column])
				if (tab[line][column] == letter) 
					tetrimino_set = 1;
		}
		if (tetrimino_set)
			i++;
		else
			tetrimino_to_set = 1;
	}
	if (!tetrimino_to_set)
	{
		ft_putendl("tous les tetriminos sont dans la grille");
		return (tab);
	}
	ft_putstr("on peut placer un tetrimino, dont, la valeur du char est ");
	ft_putchar(letter);
	ft_putstr(".\n");
	while (i--)
	{
		ft_putendl("on parcours la liste chainee");	
		list = list->next;
	}
	line = -1;
	while (tab[++line])
	{
		ft_putendl("on rentre dans la boucle de resolution pour placer un tetrimino");
		ft_putstr("la valeur de line est de ");
		ft_putnbr(line);
		ft_putstr(".\n");
		column = -1;
		while (tab[line][++column])
		{
			ft_putstr("la valeur de column est de ");
			ft_putnbr(column);
			ft_putstr(".\n");
			if ((tab = insert_tetrimino(tab, list->tetrimino, line, column)))
			{
				if ((tab = resolution(tab, list, tetriminos)))
					return (tab);
			}
			tab = tmp;
		}
	}
	ft_putendl("on sort de resolution");
	return (NULL);
}
