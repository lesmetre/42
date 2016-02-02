/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpressen <mpressen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/24 21:52:59 by mpressen          #+#    #+#             */
/*   Updated: 2016/02/02 13:24:36 by mpressen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

/*
** The get_next_line() function reads a line from stream
** with the newline character as delimiter.
** The delimiter is not included as part of the line.
** The function returns 1 if a line has been read,
** -1 if an error occurs, and 0 if end-of-file is reached.
*/

static void	create_link(int fd, t_linked_list *first, t_linked_list **list)
{
	if (!(*list = (t_linked_list*)malloc(sizeof(**list))))
		return ;
	(*list)->fd = fd;
	(*list)->str = NULL;
	(*list)->next = first;
}

static int	is_line(char *str)
{
	int	i;

	i = -1;
	while (str[++i])
		if (str[i] == '\n')
			return (1);
	return (0);
}

static int	get_line_stocked(t_linked_list **list, char **line)
{
	int				i;
	int				start;
	char			*tmp;

	i = 0;
	tmp = NULL;
	if (!(*list) || !((*list)->str))
		return (0);
	while ((*list)->str[i] && (*list)->str[i] != '\n')
		i++;
	*line = ft_strsub((*list)->str, 0, i);
	if ((*list)->str[i] && (*list)->str[++i])
	{
		start = i;
		while ((*list)->str[i])
			i++;
		tmp = ft_strsub((*list)->str, start, i - start);
	}
	ft_strdel(&((*list)->str));
	if (tmp)
		(*list)->str = tmp;
	return (1);
}

static void	init_list(int fd, t_linked_list **first, t_linked_list **list)
{
	if (!(*list))
	{
		create_link(fd, *first, list);
		*first = *list;
	}
	if (!(*list)->str)
		(*list)->str = ft_strnew(0);
}

int			get_next_line(int const fd, char **line)
{
	static t_linked_list	*first = NULL;
	t_linked_list			*list;
	int						ret;
	char					*buf;
	char					*tmp;

	if (fd < 0 || !line)
		return (-1);
	list = first;
	while (list && list->fd != fd)
		list = list->next;
	buf = ft_strnew(BUFF_SIZE + 1);
	while ((ret = read(fd, buf, BUFF_SIZE)) > 0)
	{
		init_list(fd, &first, &list);
		tmp = ft_strjoin(list->str, buf);
		ft_strdel(&(list->str));
		list->str = tmp;
		ft_bzero(buf, BUFF_SIZE + 1);
		if (is_line(list->str))
			break ;
	}
	ft_strdel(&buf);
	return (ret == -1 ? -1 : get_line_stocked(&list, line));
}
