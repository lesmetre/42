/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   resolution.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpressen <mpressen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/14 06:32:07 by mpressen          #+#    #+#             */
/*   Updated: 2016/01/22 21:03:54 by mpressen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int			resolution(char ***addr_square, t_chain *list, int tetriminos)
{
	int		tetrimino_to_set;
	int		tetrimino_set;
	int		line;
	int		column;
	char	letter;
	int		i;

//	ft_putendl("on rentre dans resolution");
	i = 0;
	tetrimino_to_set = 0;
	while (!tetrimino_to_set && i < tetriminos)
	{
//		ft_putendl("on check s'il y a un tetrimino a placer");
		tetrimino_set = 0;
		letter = 'A' + i;
		line = -1;
		while (!tetrimino_set && (*addr_square)[++line])
		{
			column = -1;
			while (!tetrimino_set && (*addr_square)[line][++column])
				if ((*addr_square)[line][column] == letter) 
					tetrimino_set = 1;
		}
		if (tetrimino_set)
			i++;
		else
			tetrimino_to_set = 1;
	}
	if (!tetrimino_to_set)
	{
//		ft_putendl("tous les tetriminos sont dans la grille");
//		ft_putendl("resolution renvoie 1 avec la solution");
		return (1);
	}
//	ft_putstr("on peut placer un tetrimino, dont, la valeur du char est ");
//	ft_putchar(letter);
//	ft_putstr(".\n");
//	ft_putstr("la valeur de i est de ");
//	ft_putnbr(i);
//	ft_putstr(".\n");
/*	while (i--)
	{
		ft_putstr("la valeur de i est de ");
		ft_putnbr(i);
		ft_putstr(".\n");
		ft_putendl("on passe a la prochaine instance");	
		list = list->next;
		print_tab(list->tetrimino);
	}*/
	if (i)
	{
//		ft_putendl("on passe a la prochaine instance");	
		list = list->next;
//		print_tab(list->tetrimino);
	}
	line = -1;
	while ((*addr_square)[++line])
	{
//		ft_putendl("on rentre dans la boucle de resolution pour placer un tetrimino");
//		ft_putstr("la valeur de line est de ");
//		ft_putnbr(line);
//		ft_putstr(".\n");
		column = -1;
		while ((*addr_square)[line][++column])
		{
//			ft_putstr("la valeur de column est de ");
//			ft_putnbr(column);
//			ft_putstr(".\n");
//			if (list->tetrimino)
//				ft_putendl("list->tetrimino est non-nul");
//			if (addr_square)
//				ft_putendl("addr_square est non-nul");
//			ft_putendl("on rentre dans insert_tetrimino");
			if (insert_tetrimino(addr_square, list->tetrimino, line, column))
			{
//				print_tab (*addr_square);
				if (resolution(addr_square, list, tetriminos))
				{
//					ft_putendl("resolution renvoie 1");
					return (1);
				}
			}
//			print_tab(*addr_square);
//			ft_putstr("on efface le tetrimino incomplet dont la lettre est ");
//			ft_putchar(letter);
//			ft_putstr(".\n");
			erase_tetrimino(addr_square, letter);
//			ft_putendl("on verifie");
//			print_tab (*addr_square);
		}
	}
//	ft_putendl("resolution renvoie 0");
	return (0);
}
