/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpressen <mpressen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/11 23:27:33 by mpressen          #+#    #+#             */
/*   Updated: 2016/01/14 02:06:20 by mpressen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	print_list(t_chain *list)
{
	int i;

	while (list)
	{
		i = -1;
		while (list->tetrimino[++i])
			ft_putendl(list->tetrimino[i]);
		free_tab(list->tetrimino);
		free(list);
		if ((list = list->next))
			ft_putstr("\n");
	}
}

int		main(int ac, char **av)
{
	int		fd;
	char	*buf;
	char	*stock;
	t_chain	*list;

	list = NULL;
	stock = (char *)malloc(sizeof(*stock));
	stock[0] = '\0';
	buf = (char *)malloc(sizeof(*buf) * BUFF_SIZE + 1);
	if (ac == 2)
	{
		fd = open(av[1], O_RDONLY);
		if (fd == -1)
			return (1);
		while (read(fd, buf, BUFF_SIZE))
			stock = ft_strjoin(stock, buf);
		free(buf);
		if (list_valid(stock) && tetrimino_valid(stock))
			list = stock_tetriminos(stock);
		free(stock);
		print_list(list);
		if ((close(fd)) == -1)
			return (1);
	}
	return (0);
}
