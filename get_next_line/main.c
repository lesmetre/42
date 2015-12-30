/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpressen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/30 22:43:39 by mpressen          #+#    #+#             */
/*   Updated: 2015/12/30 23:49:40 by mpressen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <stdlib.h>
#define BUF_SIZE    1

void    ft_putstr_fd(int fd, char *str)
{
    while (*str)
        write(fd, str++, 1);
}

int		get_next_line(int const fd, char **line)
{
	int		in_line;

	in_line = 1;
	while (in_line && read (fd, *line, BUF_SIZE))
	{
		if (**line == '\n')
			in_line = 0;
		else
			ft_putstr_fd(1, *line);
	}
	if (in_line == 0)
		return (1);
	if (in_line == 1)
		return (0);
	else
		return (-1);
}

int		main(int ac, char **av)
{
	int		fd;
	char	**line;

	line = (char **)malloc(sizeof(*line) * BUF_SIZE + 1);
	*line = (char *)malloc(sizeof(**line) * BUF_SIZE + 1);
	if (ac == 2)
	{
		fd = open(av[1], O_RDONLY);
		if (fd == -1)
			return (1);
		while (get_next_line(fd, line))
			ft_putstr_fd(1, "\n");
		close (fd);
	}
	free(line);
	return (0);
}
