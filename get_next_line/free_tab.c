/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_tab.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpressen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/28 23:10:03 by mpressen          #+#    #+#             */
/*   Updated: 2016/01/04 20:08:33 by mpressen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdlib.h>

void	free_tab(char **tab)
{
	int i;

	i = -1;
	while (tab[++i])
	{
		free(tab[i]);
		tab[i] = NULL;
	}
	free(tab);
	tab = NULL;
}

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# define BUFF_SIZE  1

# include "libft.h"
# include <stdlib.h>
# include <unistd.h>
# include <sys/types.h>
# include <sys/uio.h>

typedef struct      s_list
{
    int             fd;
    char            *stock;
    struct s_list   *next;
    struct s_list   *prev;
}                   t_list;

int     get_next_line(int const fd, char **line);

#endif

#include "get_next_line.h"

int     main(int ac, char **av)
{
    char    *line;
    int     fd;
    int     fd2;

    line = NULL;
    fd = open(av[1], O_RDONLY);
    fd2 = open(av[2], O_RDONLY);
    if (fd == -1 || fd2 == -1)
        return (1);
    while (get_next_line(fd, &line))
    {
        ft_putendl(line);
        get_next_line(fd2, &line);
        ft_putendl(line);
    }
    ft_strdel(&line);
    if (close(fd) || close(fd2))
        return (1);
    return (0);
}

#include "get_next_line.h"

int     get_next_line(int const fd, char **line)
{
    static t_list       *fd_stock = {0, NULL, NULL, NULL};

    if (fd < 0 || !line)
        return (-1);
    while (fd_stock->fd != fd && fd_stock->prev)
        fd_stock = fd_stock->prev;
    while (fd_stock->fd != fd)
        fd_stock = fd_stock->next;
    if (!fd_stock)


        stock_fd[fd] = ft_strnew(1);
}
