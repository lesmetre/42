/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpressen <mpressen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/24 22:31:44 by mpressen          #+#    #+#             */
/*   Updated: 2016/01/29 03:08:07 by mpressen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <fcntl.h>

int		main(int ac, char **av)
{
    char	*line;
    int		fd;
	int		fd2;

    line = NULL;
	if (ac != 3)
		return (0);
	fd = open(av[1], O_RDONLY);
	fd2 = open(av[2], O_RDONLY);
    if (fd == -1 || fd2 == -1)
        return (1);
    get_next_line(fd, &line);
	ft_putendl("--------------------------");
	ft_putendl(line);
	ft_putendl("--------------------------");
	get_next_line(fd2, &line);
    ft_putendl("--------------------------");
    ft_putendl(line);
    ft_putendl("--------------------------");
	get_next_line(fd, &line);
    ft_putendl("--------------------------");
    ft_putendl(line);
    ft_putendl("--------------------------");
	get_next_line(fd2, &line);
    ft_putendl("--------------------------");
    ft_putendl(line);
    ft_putendl("--------------------------");
	ft_strdel(&line);
	if (close(fd) || close(fd2))
        return (1);
    return (0);
}
