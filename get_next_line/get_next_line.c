/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpressen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/30 22:43:39 by mpressen          #+#    #+#             */
/*   Updated: 2016/01/06 06:37:32 by mpressen         ###   ########.fr       */
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

	if (split && split[i + 1])
	{
		ft_putstr(split[i + 1]);
		i++;
		if (split[i + 1])
			return (1);
	}
	i = 0;
	while ((ret = read(fd, *line, BUFF_SIZE)) > 0)
	{
		(*line)[ret] = '\0';
		if ((*line)[0] != '\n' || ret != 1)
		{
			split = ft_strsplit(*line, '\n');
			if ((*line)[0] == '\n')
			{
				i = -1;
				return (1);
			}
			ft_putstr(split[0]);
			if ((*line)[ret - 1] == '\n')
				return (1);
			if (split[1])
				return (1);
		}
		else
		{
			if ((ret = read(fd, *line, BUFF_SIZE)) > 0)
			{
				split = (char **)malloc(sizeof(*split) * 1);
				split[0] = *line;
				i = -1;
				return (1);
			}
		}
	}
	return (ret);
}
