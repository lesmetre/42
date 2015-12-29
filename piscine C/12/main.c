/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpressen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/29 20:56:13 by mpressen          #+#    #+#             */
/*   Updated: 2015/12/29 23:34:35 by mpressen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <fcntl.h>

void	ft_putchar_fd(int fd, char c)
{
	write(fd, &c, 1);
}

void	ft_putstr_fd(int fd, char *str)
{
    while (*str)
        write(fd, str++, 1);
}

int		ft_isdigit(int c)
{
    if (c >= '0' && c <= '9')
        return (1);
    return (0);
}

int		ft_isspace_full(int c)
{
    if (c == '\n' || c == '\f' || c == '\r'
		|| c == '\v' || c == ' ' || c == '\t')
        return (1);
    return (0);
}

int		ft_atoi(const char *str)
{
    size_t  count;
    int     res;
    int     sign;

    count = 0;
    res = 0;
    sign = 1;
    while (ft_isspace_full((int)str[count]))
        count++;
    if (str[count] == '-' || str[count] == '+')
    {
        if (str[count] == '-')
            sign = -1;
        count++;
    }
    while (ft_isdigit((int)str[count]))
    {
        res = res * 10 + str[count] - '0';
        count++;
    }
    return (res * sign);
}

int		main(int ac, char **av)
{
	int		fd;
	char	buf;
	int		i;

	i = 2;
	if (ac < 4)
		return (1);
	while (++i < ac)
	{
		fd = open(av[i], O_RDONLY, O_APPEND);
		if (fd >= 0)
		{
			ft_putstr_fd(1, "==> ");
			ft_putstr_fd(1, av[i]);
			ft_putstr_fd(1, " <==\n");
			lseek(fd, -(ft_atoi(av[2])), SEEK_END);
			while (read(fd, &buf, 1))
				ft_putchar_fd(1, buf);
			if (i < ac - 1)
				ft_putstr_fd(1, "\n");
			close(fd);
		}
		else
		{
			ft_putstr_fd(2, "tail: ");
			ft_putstr_fd(2, av[i]);
			ft_putstr_fd(2, ": No such file or directory\n");
		}
	}
	return (0);
}
