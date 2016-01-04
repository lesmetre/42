/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpressen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/30 22:43:39 by mpressen          #+#    #+#             */
/*   Updated: 2016/01/04 23:14:43 by mpressen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <stdlib.h>
#include "get_next_line.h"
#include "libft.h"
#include <stdio.h>

int		get_next_line(int const fd, char **line)
{
	int				ret;
	static char		**split = NULL;
	int				in_line;
	static int		i = 0;
	
	ret = 0;
//	ft_putendl("on rentre dans la fonction getnextline");
	in_line = 1;
	if (split && split[i + 1])
	{
//		ft_putendl("on rentre dans la condition ou on a stocke encore une ligne");
		ft_putstr(split[i + 1]);
		i++;
		if (split[i + 1])
			return (1);
	}
	i = 0;
	split = NULL;
	while (in_line && (ret = read(fd, *line, BUF_SIZE)) > 0)
	{
//		printf("le read retourne %d", ret);
//		ft_putendl("on rentre dans la boucle principale du read");
		(*line)[ret] = '\0';
		split = ft_strsplit(*line, '\n');
		if (split[0][0])
		{
			ft_putstr(split[0]);
			if (split[1])
			{
//				ft_putendl("on rentre dan la condition ou il y a un retour-ligne dans le buffer");
				return (1);
			}
		}
		else
			in_line = 0;
	}
	if (ret == -1)
		return (-1);
	if (ret > 0)
	{
//		ft_putendl("on retourne 1 pour lire la prochaine ligne");
		return (1);
	}
//	ft_putendl("Il n'y a pas d'autres lignes a lire");
	return (0);
}
