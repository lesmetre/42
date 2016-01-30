/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpressen <mpressen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/24 22:31:44 by mpressen          #+#    #+#             */
/*   Updated: 2016/01/30 01:27:41 by mpressen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <fcntl.h>

int		main(int ac, char **av)
{
	char	*line;
	int		fd;
	int		ret;

	line = NULL;
	if (ac != 2)
		return (0);
	fd = open(av[1], O_RDONLY);
	if (fd == -1)
		return (1);
	while ((ret = get_next_line(fd, &line) > 0))
	{
		ft_putnbr(ret);
		ft_putstr("\n");
		ft_putendl("--------------------------");
		ft_putendl(line);
		ft_putendl("--------------------------");
	}
	ft_putnbr(ret);
	ft_putstr("\n");
	ft_strdel(&line);
	if (close(fd))
		return (1);
	return (0);
}
