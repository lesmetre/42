/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpressen <mpressen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/10 16:37:38 by mpressen          #+#    #+#             */
/*   Updated: 2016/02/10 17:32:16 by mpressen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <unistd.h>
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
	while ((ret = get_next_line(fd, &line)))
		ft_putendl(line);
	ft_strdel(&line);
	if (close(fd))
		return (1);
	return (0);
}
