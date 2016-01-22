/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   insert_tetrimino.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpressen <mpressen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/22 02:08:46 by mpressen          #+#    #+#             */
/*   Updated: 2016/01/22 21:02:32 by mpressen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		insert_tetrimino(char ***addr_tab, char **tetrimino, int line, int column)
{
	int i;
	int j;
	int start_line;
	int start_column;
	int block_placed;
	int stop;
	int x;

//	ft_putendl("on rentre dans insert_tetrimino");
	i = -1;
	block_placed = 0;
	stop = 0;
	if((*addr_tab)[line][column] != '.')
		return (0);
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
	x = 0;
	while ((*addr_tab)[0][x])
		x++;
	while (i < 4)
	{
//		ft_putendl("on rentre dans la boucle pour placer les blocks");
//		ft_putstr("la valeur de i est ");
//		ft_putnbr(i);
//		ft_putstr(".\n");
		j = -1;
		while (++j < 4)
		{
//			ft_putstr("la valeur de j est ");
//			ft_putnbr(j);
//			ft_putstr(".\n");
			if (tetrimino[i][j] != '.')
			{
//				ft_putstr("on a identifie un block du tetrimino");
				if (line + i - start_line >= 0 && column + j - start_column >= 0
					&& line + i - start_line < x && column + j - start_column < x
					&& (*addr_tab)[line + i - start_line][column + j - start_column] == '.')
				{
//					ft_putendl(" et on peut le placer dans la grille de solution");
					(*addr_tab)[line + i - start_line][column + j - start_column] = tetrimino[i][j];
					block_placed++;
					if (block_placed == 4)
					{
//						ft_putendl("on a place le tetrimino sur la grille de solution");
						return (1);
					}
				}
				else
				{
//					ft_putendl(" mais on ne peut pas le placer dans la grille");
					return (0);
				}
			}
		}
		i++;
	}
//	ft_putendl("on a pas pu placer le tetrimino");
	return (0);
}
