/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpressen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/30 22:43:39 by mpressen          #+#    #+#             */
/*   Updated: 2016/01/04 21:19:24 by mpressen         ###   ########.fr       */
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
	char			**split;
	static char		*stock = NULL;
	int				in_line;

	in_line = 1; 
	if (stock)
	{
		split = ft_strsplit(stock, '\n');
		ft_putstr_fd(split[0], 1);
		if (strncmp(split[0], stock, ft_strlen(stock)) != 0)
			stock = ft_strchr(stock, '\n');
		else
			stock = NULL;
		return (1);
	}
	else
	{
		while (in_line && (ret = read (fd, *line, BUF_SIZE)) >= 1)
		{
			(*line)[ret] = '\0';
			split = ft_strsplit(*line, '\n');
			ft_putstr_fd(split[0], 1);
			if (strncmp(split[0], *line, BUF_SIZE) != 0)
			{
				stock = ft_strchr(*line, '\n');
				in_line = 0;
			}
		}
	}
//	free_tab(split);
	if (ret == -1)
		return (-1);
	if (ret > 0)
		return (1);
//	if(ret == 0 && stock)
//		return (1);
	else
	{
//		free(stock);
		return (0);
	}
}
