/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpressen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/31 00:32:42 by mpressen          #+#    #+#             */
/*   Updated: 2015/12/31 00:36:16 by mpressen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <stdlib.h>
#include "get_next_line.h"
//#include "libft.h"

int     main(int ac, char **av)
{
    int     fd;
    char    *buf;

    buf = (char *)malloc(sizeof(*buf) * BUF_SIZE + 1);
    if (ac == 2)
    {
        fd = open(av[1], O_RDONLY);
        if (fd == -1)
            return (1);
        while (get_next_line(fd, &buf))
            ft_putstr_fd(1, "\n");
        close (fd);
    }
    free(buf);
    return (0);
}
