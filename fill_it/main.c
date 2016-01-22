/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpressen <mpressen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/11 23:27:33 by mpressen          #+#    #+#             */
/*   Updated: 2016/01/22 21:04:23 by mpressen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int			main(int ac, char **av)
{
	int				fd;
	char			*buf;
	char			*stock;
	t_chain			*list;

	list = NULL;
	stock = ft_memalloc(1);
	buf = ft_memalloc(BUFF_SIZE + 1);
	if (ac == 2)
	{
		fd = open(av[1], O_RDONLY);
		if (fd == -1)
			return (1);
		while (read(fd, buf, BUFF_SIZE))
			stock = ft_strjoin(stock, buf);
		ft_strdel(&buf);
		if (list_valid(stock) && tetrimino_valid(stock))
		{
			list = stock_tetriminos(stock);
			ft_strdel(&stock);
//			ft_putendl("on affiche les tableau de string stocke dans la liste chaine");
//			print_list(list);
//			ft_putstr("---------------------\n");
			fillit(list);
//			free_list(&list);
		}
		if ((close(fd)) == -1)
			return (1);
	}
	return (0);
}
