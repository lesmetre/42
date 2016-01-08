/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpressen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/31 00:32:42 by mpressen          #+#    #+#             */
/*   Updated: 2016/01/08 02:02:53 by mpressen         ###   ########.fr       */
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
	int		i;

	i = 0;
	buf = (char *)malloc(sizeof(*buf) * BUFF_SIZE + 1);
	if (ac == 2)
	{
		fd = open(av[1], O_RDONLY);
		if (fd == -1)
			return (1);
		while (get_next_line(fd, &buf))
			ft_putstr("\n");
		if (close(fd))
			return (1);
	}
	free(buf);
	return (0);
}
