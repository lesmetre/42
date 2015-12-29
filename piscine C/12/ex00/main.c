/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpressen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/29 20:56:13 by mpressen          #+#    #+#             */
/*   Updated: 2015/12/29 22:11:26 by mpressen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <fcntl.h>

void	ft_putstr_fd(int fd, char *str)
{
    while (*str)
        write(fd, str++, 1);
}

int		main(int ac, char **av)
{
	int		fd;
	char	buf;

    if (ac == 1)
    {
        ft_putstr_fd(2, "File name missing.\n");
        return (1);
    }
	if (ac > 2)
	{
		ft_putstr_fd(2, "Too many arguments.\n");
		return (1);
	}
	fd = open(av[1], O_RDONLY);
	while (read(fd, &buf, 1))
		ft_putstr_fd(1, &buf);
	close(fd);
	return (0);
}
