/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   resolution.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpressen <mpressen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/14 06:32:07 by mpressen          #+#    #+#             */
/*   Updated: 2016/01/14 13:37:24 by mpressen         ###   ########.fr       */
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
	int no_can_do;
	int x;

//	ft_putendl("on rentre dans insert_tetrimino");
	i = -1;
	block_placed = 0;
	if(tab[line][column] != '.')
		return (NULL);
	while (!block_placed && tetrimino[++i])
	{
		j = -1;
		while(!block_placed &&tetrimino[i][++j])
		{
			if (tetrimino[i][j] != '.')
			{
				start_line = i;
				start_column = j;
				tab[column][line] = tetrimino[i][j];
				block_placed++;
			}		
		}
	}
//	ft_putendl("on a place le premier block");
	no_can_do = 0;
	x = 0;
	while (tab[0][x])
		x++;
	while (!no_can_do && tetrimino[++i])
	{
		j = -1;
		while (!no_can_do && tetrimino[i][++j])
		{
			if (tetrimino[i][j] != '.')
			{
				if (line + i - start_line >= 0 && column + j - start_column >= 0 && line + i - start_line < x && column + j - start_column < x && tab[line + i - start_line][column + j - start_column] == '.')
				{
					tab[line + i - start_line][column + j - start_column] = tetrimino[i][j];
					block_placed++;
//					ft_putendl("on a place un autre block");
				}
				else
					no_can_do = 1;
			}
		}
	}
//	ft_putendl("on sort de insert_tetrimino");
	if (block_placed == 4)
		return (tab);
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
		ft_putendl("on ");
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
		return (tab);
	ft_putendl("on a place le premier block");
	ft_putstr("la valeur du char place est ");
	ft_putchar(letter);
	ft_putstr(".\n");
	while (i--)
		list = list->next;
	line = -1;
	while (tab[++line])
	{
		ft_putendl("on rentre dans la boucle pour placer les autres blocks");
		column = -1;
		while (tab[line][++column])
		{
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
