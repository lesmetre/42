/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpressen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/30 22:43:39 by mpressen          #+#    #+#             */
/*   Updated: 2016/01/05 03:25:16 by mpressen         ###   ########.fr       */
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

//	ret = 0;
	ft_putendl("on rentre dans la fonction getnextline");
	in_line = 1;
	if (split && split[i + 1])
	{
		ft_putendl("on rentre dans la condition ou on a stocke encore une ligne");
		ft_putstr(split[i + 1]);
		i++;
		if (split[i + 1])
			return (1);
	}
	i = 0;
//	split = NULL;
	while (in_line && (ret = read(fd, *line, BUFF_SIZE)) > 0)
	{
//		printf("le read retourne %d", ret);
//		ft_putendl("on rentre dans la boucle principale du read");
		(*line)[ret] = '\0';
//		if ((*line)[0] != '\n' || BUFF_SIZE > 1)
//		{
		if (BUFF_SIZE == 1 && (*line)[0] == '\n')
			in_line = 0;
		else
		{
			split = ft_strsplit(*line, '\n');
			if (split[0][0])
			{
				ft_putstr(split[0]);
				if (split[1])				//  || (*line)[BUFF_SIZE - 1] == '\n')
				{
//					ft_putendl("on rentre dan la condition ou il y a un retour-ligne dans le buffer");
					return (1);
				}
				
			}
			else
				if (ret == BUFF_SIZE)
					in_line = 0;
		}
	}
//	if (ret == 1 && (*line)[0] == '\n' && BUFF_SIZE > 1)
//		ret = 0;
	return (ret);
}
