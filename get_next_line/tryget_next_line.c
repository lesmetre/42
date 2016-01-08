/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpressen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/30 22:43:39 by mpressen          #+#    #+#             */
/*   Updated: 2016/01/08 08:56:07 by mpressen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <stdlib.h>
#include "get_next_line.h"
#include "libft.h"

int		buffer_full_return_line(char **line)
{
	int i;

	i = -1;
	while ((*line)[++i])
	{
		if ((*line)[i] != '\n')
			return (0);
	}
	return (1);
}

int		get_next_line(int const fd, char **line)
{
	int				ret;
	static char		*stock = NULL;
	char			**split;
	int				line_to_ignore;

//	ft_putendl("on rentre dans get next line ---------------------");
	if (stock)
	{
//		ft_putendl("on rentre dans la condition ou on a stocke une chaine");
		while (buffer_full_return_line(line))
		{
//			ft_putstr("la fonction de check retourne ");
//			ft_putnbr(buffer_full_return_line(line));
//			ft_putstr("\n");
//			ft_putendl("on rentre dans la condition ou ce quon veut split ne contient que des retour ligne");
			line_to_ignore = 1;
			if ((ret = read(fd, *line, BUFF_SIZE)) > 0)
				(*line)[ret] = '\0';
			else
				return (ret);
		}
		if (ret == BUFF_SIZE && line_to_ignore == 1)	 // i = -1
		{
			stock = *line;
			return (1);
		}
		split = ft_strsplit(stock, '\n');
		ft_putstr(split[0]);
		if (split[1])
		{
			while (stock[0] == '\n')
				stock = ft_strchr(stock, '\n') + 1;
			stock = ft_strchr(stock, '\n') + 1;
			free_tab(split);
			return (1);
		}
		free_tab(split);
	}
	while ((ret = read(fd, *line, BUFF_SIZE)) > 0)
	{
//		ft_putendl("on rentre dans la boucle du read");
//		ft_putstr("read lit ");
//		ft_putnbr(ret);
//		ft_putendl(" caracteres");
		line_to_ignore = 0;
		(*line)[ret] = '\0';
		while (buffer_full_return_line(line))
		{
//			ft_putstr("la fonction de check retourne ");
//			ft_putnbr(buffer_full_return_line(line));
//			ft_putstr("\n");
//			ft_putendl("on rentre dans la condition ou ce quon veut split ne contient que des retour ligne");
			line_to_ignore = 1;
			if ((ret = read(fd, *line, BUFF_SIZE)) > 0)
				(*line)[ret] = '\0';
			else
				return (ret);
		}
		if (ret == BUFF_SIZE && line_to_ignore == 1)	// && !stock)
		{
			stock = *line;
			return (1);
		}
//		ft_putendl("on peut effectue un split");
		split = ft_strsplit(*line, '\n');
		if (!split)
			return (-1);
		if (!(line_to_ignore) && (*line)[0] == '\n' && !stock)
		{
//			ft_putendl("on rentre dans la condition ou ce quon veut split commence par un retour ligne");
			stock = *line;
			return (1);
		}
		ft_putstr(split[0]);
		if (split[1])
		{
			stock = ft_strchr(*line, '\n') + 1;
			return (1);
		}
		if ((*line)[ret - 1] == '\n')
		{
			if ((ret = read(fd, *line, BUFF_SIZE)) > 0)
			{
				(*line)[ret] = '\0';
//				ft_putendl("on rentre dans la condition ou ce quon split finit par un retour ligne et que le fichier continue");
				stock = *line;
				return (1);
			}
//			ft_putendl("Il n'y a plus de ligne a lire");
			return (0);
		}
	}
//	ft_putendl("Il n'y a plus de ligne a lire");
//	ft_putstr("get next line retourne ");
//	ft_putnbr(ret);
//	ft_putendl(".");
	return (ret);
}
