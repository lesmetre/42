/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpressen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/30 22:43:39 by mpressen          #+#    #+#             */
/*   Updated: 2015/12/31 00:35:27 by mpressen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <stdlib.h>
#include "get_next_line.h"
//#include "libft.h"

void    ft_putstr_fd(int fd, char *str)
{
    while (*str)
        write(fd, str++, 1);
}

int		get_next_line(int const fd, char **line)
{
	int		in_line;
	int		ret;
	
	in_line = 1;
	while (in_line && (ret = read (fd, *line, BUF_SIZE)) >= 1)
	{
		if (**line == '\n')
			in_line = 0;
		else
			ft_putstr_fd(1, *line);
	}
	if (ret == -1)
		return (-1);
	if (ret > 0)
		return (1);
	else
		return (0);
}
