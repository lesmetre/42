/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpressen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/31 00:32:42 by mpressen          #+#    #+#             */
/*   Updated: 2016/01/09 06:37:12 by mpressen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <stdlib.h>
#include "get_next_line.h"
#include "libft.h"

int		main(int ac, char **av)
{
	int		fd;
	char	*buf;
	char	*buf2;
	char	*buf3;
	char	*buf4;
	char	*buf5;
	char	*buf6;
	char	*buf7;
	char	*buf8;
	char	*buf9;
	int		i;

	i = 0;
	buf = (char *)malloc(sizeof(*buf) * BUFF_SIZE + 1);
	buf2 = (char *)malloc(sizeof(*buf) * BUFF_SIZE2 + 1);
	buf3 = (char *)malloc(sizeof(*buf) * BUFF_SIZE3 + 1);
	buf4 = (char *)malloc(sizeof(*buf) * BUFF_SIZE4 + 1);
	buf5 = (char *)malloc(sizeof(*buf) * BUFF_SIZE5 + 1);
	buf6 = (char *)malloc(sizeof(*buf) * BUFF_SIZE6 + 1);
	buf7 = (char *)malloc(sizeof(*buf) * BUFF_SIZE7 + 1);
	buf8 = (char *)malloc(sizeof(*buf) * BUFF_SIZE8 + 1);
	buf9 = (char *)malloc(sizeof(*buf) * BUFF_SIZE9 + 1);
	if (ac == 2)
	{
		fd = open(av[1], O_RDONLY);
		if (fd == -1)
			return (1);
		while (get_next_line(fd, &buf))
			ft_putstr("\n");
		if (close(fd))
            return (1);
		ft_putstr("\n");
		fd = open(av[1], O_RDONLY);
		while (get_next_line(fd, &buf2))
            ft_putstr("\n");
		if (close(fd))
            return (1);
		ft_putstr("\n");
		fd = open(av[1], O_RDONLY);
		while (get_next_line(fd, &buf3))
            ft_putstr("\n");
		if (close(fd))
            return (1);
		ft_putstr("\n");
		fd = open(av[1], O_RDONLY);
		while (get_next_line(fd, &buf4))
            ft_putstr("\n");
		if (close(fd))
            return (1);
		ft_putstr("\n");
		fd = open(av[1], O_RDONLY);
		while (get_next_line(fd, &buf5))
            ft_putstr("\n");
		if (close(fd))
            return (1);
		ft_putstr("\n");
		fd = open(av[1], O_RDONLY);
		while (get_next_line(fd, &buf6))
            ft_putstr("\n");
		if (close(fd))
            return (1);
		ft_putstr("\n");
		fd = open(av[1], O_RDONLY);
		while (get_next_line(fd, &buf7))
            ft_putstr("\n");
		if (close(fd))
            return (1);
		ft_putstr("\n");
		fd = open(av[1], O_RDONLY);
		while (get_next_line(fd, &buf8))
            ft_putstr("\n");
		if (close(fd))
            return (1);
		ft_putstr("\n");
		fd = open(av[1], O_RDONLY);
		while (get_next_line(fd, &buf9))
            ft_putstr("\n");
		if (close(fd))
			return (1);
	}
	free(buf);
	return (0);
}
