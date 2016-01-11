/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpressen <mpressen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/11 23:27:33 by mpressen          #+#    #+#             */
/*   Updated: 2016/01/11 23:36:55 by mpressen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include "libft.h"
#include "fillit.h"

int		main(int ac, char **av)
{
	int		fd;
	char	*buf;
	char	*stock;

	stock = (char *)malloc(sizeof(*stock));
	stock[0] = '\0';
	buf = (char *)malloc(sizeof(*buf) * BUFF_SIZE + 1);
	if (ac == 2)
	{
		fd = open(av[1], O_RDONLY);
		if (fd == -1)
			return (1);
		while (read(fd, buf, BUFF_SIZE))
			stock = ft_strjoin(stock, buf);
		if(list_valid(stock) && tetrimino_valid(stock))
			ft_putstr(stock);
		if((close(fd)) == -1)
			return (1);
	}
	free(buf);
	return (0);
}
