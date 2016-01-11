/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpressen <mpressen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/11 10:15:54 by mpressen          #+#    #+#             */
/*   Updated: 2016/01/11 23:30:16 by mpressen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "fillit.h"

int		list_valid(char *str)
{
	int i;
	int count_blocks;
	int tetrimino;
	

	i = 0;
	tetrimino = 1;
	while (str[i])
	{
		count_blocks = 0;
		while (str[i] && i < tetrimino * 21) 
		{
			if (str[i] == '\n' && ((i - tetrimino) % 5 == 3 || (i - tetrimino) % 20 == 19))
				i++;
			else
			{
				if (str[i] != '.' && str[i] != '#')
				{
					ft_putendl("tetrimino non valide: grille de 16 non valide");
					return (0);
				}
				if (str[i] == '#')
					count_blocks++;
				i++;	
			}
		}
		if (count_blocks != 4)
		{
			ft_putendl("tetrimino non valide : plus ou moins de 4 blocks");
			return (0);
		}
		tetrimino++;
	}
	if (i % 21 != 20)
	{
		ft_putendl("tetrimino non valide : dernier tetrimino");
		return (0);
	}
//	ft_putendl("liste de tetrimino valide");
	return (1);
}

int		tetrimino_valid(char *str)
{
	int i;
	int tetrimino;
	int	connections;
	int	is_connection;

//	ft_putendl("on rentre dans tetrimino_valid");
	i = 0;
	tetrimino = 1;
	while (str[i])
	{
		connections = 0;
		while (i < tetrimino * 21)
		{
//			ft_putstr("i a la valeur de ");
//			ft_putnbr(i);
//			ft_putstr(".\n");
			if (str[i] == '#')
			{
				is_connection = 0;
				if (i % 21 > 3 && str[i - 5] == '#')
				{
					connections++;
					is_connection = 1;
				}
				if (i % 21 < 15 && str[i + 5] == '#')
				{
					connections++;
					is_connection = 1;
				}
				if (i % 5 - tetrimino + 1 != 0 && str[i - 1] == '#')
				{
					connections++;
					is_connection = 1;
				}
				if (i % 5 - tetrimino + 1 != 3 && str[i + 1] == '#')
				{
					connections++;
					is_connection = 1;
				}
				if (!is_connection)
				{
					ft_putendl("tetrimino non valide : block de tetrimino non connecte");
					return (0);
				}
//				ft_putstr("il y a ");
//				ft_putnbr(connections);
//				ft_putstr(" connections.\n");
			}
			i++;
		}
		if (connections < 6)
		{
			ft_putendl("tetrimino non valide : block de tetrimino non connecte");
			return (0);
		}
//		ft_putendl("tetrimino valide");
		tetrimino++;
	}
	return (1);	
}
