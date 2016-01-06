/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpressen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/30 22:43:39 by mpressen          #+#    #+#             */
/*   Updated: 2016/01/06 23:16:07 by mpressen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <stdlib.h>
#include "get_next_line.h"
#include "libft.h"

int		get_next_line(int const fd, char **line)
{
	int				ret;
	static char		**split = NULL;
	static int		i = 0;

//	ft_putendl("on rentre dans get next line ---------------------");
	if (split && split[i + 1])
	{
//		ft_putendl("on rentre dans la condition ou split stock une chaine");
		ft_putstr(split[i + 1]);
		i++;
		if (split[i + 1])
			return (1);
	}
	i = 0;
	while ((ret = read(fd, *line, BUFF_SIZE)) > 0)
	{
//		ft_putendl("on rentre dans la boucle du read");
//		ft_putstr("read lit ");
//		ft_putnbr(ret);
//		ft_putendl(" caracteres");
		(*line)[ret] = '\0';
		if ((*line)[0] != '\n' || ret != 1)
		{
//			ft_putendl("on rentre dans la condition ou split est effectue");
			split = ft_strsplit(*line, '\n');
			if ((*line)[0] == '\n')
			{
//				ft_putendl("on rentre dans la condition ou ce quon split commence par un retour ligne");
				i = -1;
				return (1);
			}
			ft_putstr(split[0]);
			if (split[1])
				return (1);
			if ((*line)[ret - 1] == '\n')
			{
				if ((ret = read(fd, *line, BUFF_SIZE)) > 0)
				{
//					ft_putendl("on rentre dans la condition ou ce quon split finit par un retour ligne et que le fichier continue");
					split = ft_strsplit(*line, '\n');
					i = -1;
					return (1);
				}
//				ft_putendl("Il n'y a plus de ligne a lire");
				return (0);
			}
		}
		else
		{
//			ft_putendl("on rentre dans la condition ou le buffer ne contient que des retour ligne");
			if ((ret = read(fd, *line, BUFF_SIZE)) > 0)
			{
//				ft_putendl("on rentre dans la boucle du read");
//				ft_putstr("read lit ");
//				ft_putnbr(ret);
//				ft_putendl(" caracteres");
				if ((split = (char **)malloc(sizeof(*split) * 1)))
				{
//					ft_putendl("malloc reussi");
					split[0] = *line;
					split[1] = NULL;
					i = -1;
					return (1);
				}
				return (-1);
			}
		}
	}
//	ft_putendl("Il n'y a plus de ligne a lire");
//	ft_putstr("get next line retourne ");
//	ft_putnbr(ret);
//	ft_putendl(".");
	return (ret);
}
