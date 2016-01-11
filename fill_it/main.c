/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpressen <mpressen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/11 10:15:54 by mpressen          #+#    #+#             */
/*   Updated: 2016/01/11 13:35:40 by mpressen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
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
	return (1);
}

int		tetrimino_valid(char *str)
{
	int i;
	int tetrimino;
	int	connections;

	ft_putendl("on rentre dans tetrimino_valid");
	i = 0;
	tetrimino = 1;
	while (str[i])
	{
		while (i < tetrimino * 21)
		{
			connections = 0;
			if (str[i] == '#')
			{
				if (!((i % 21 > 3 && str[i - 5] == '#') || (i % 21 < 15 && str[i + 5] == '#') || (i % 5 - tetrimino + 1 != 0 && str[i - 1] == '#' ) || (i % 5 - tetrimino + 1 != 3 && str[i + 1] == '#')))
				{
					ft_putendl("tetrimino non valide : block de tetrimino non connecte");
					return (0);
				}
				else
					connections++;
			}
			i++;
		}
		if (connections < 6)
		{
			ft_putendl("tetrimino non valide : block de tetrimino non connecte");
			return (0);
		}
		ft_putendl("tetrimino valide");
		tetrimino++;
	}
	return (1);	
}

int		main(int ac, char **av)
{
	int		fd;
	char	*buf;
	char	*stock;

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
		if(list_valid(stock) && tetrimino_valid(stock))
			ft_putstr(stock);
		if((close(fd)) == -1)
			return (1);
	}
	free(buf);
	return (0);
}
