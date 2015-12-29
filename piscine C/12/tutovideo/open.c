/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   open.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpressen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/29 19:16:12 by mpressen          #+#    #+#             */
/*   Updated: 2015/12/29 20:47:44 by mpressen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test.h"
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

#define BUF_SIZE	10

void	ft_putstr_fd(int fd, char *str)
{
	while (*str)
		write(fd, str++, 1);
}

void	ft_putchar_fd(int fd, char c)
{
	write(fd, &c, 1);
}

int		main(void)
{
	int		fd;
	int		ret;
	char	buf[BUF_SIZE + 1];

	fd = open("42", O_RDONLY);
	if (fd == -1)
	{
		ft_putstr_fd(1, "open() failed\n");
		return (1);
	}
	while ((ret = read(fd, buf, BUF_SIZE)))
	{
		buf[ret] = '\0';
		ft_putnbr(ret);
		ft_putstr_fd(1, buf);
		lseek(fd, -10, SEEK_END);
	}
	ft_putnbr(ret);
//	ft_putnbr(fd);
//	ft_putstr_fd(fd, "Hello World !\n");
	if (close(fd) == -1)
	{
		ft_putstr_fd(1, "\nclose() failed\n");
		return (1);
	}
	return (0);

}
