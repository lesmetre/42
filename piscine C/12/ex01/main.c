/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpressen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/29 20:56:13 by mpressen          #+#    #+#             */
/*   Updated: 2015/12/29 22:48:10 by mpressen         ###   ########.fr       */
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
	int		i;

	i = 0;
	if (ac < 2 || av[1][0] == '-')
		while (read(0, &buf, 1))
			ft_putstr_fd(1, &buf);
	else
		while (++i < ac)
		{
			fd = open(av[i], O_RDONLY);
			if (fd >= 0)
			{
				while (read(fd, &buf, 1))
					ft_putstr_fd(1, &buf);
				close(fd);
			}
			else
			{
				ft_putstr_fd(2, "cat: ");
				ft_putstr_fd(2, av[i]);
				ft_putstr_fd(2, ": No such file or directory\n");
			}
		}
	return (0);
}
