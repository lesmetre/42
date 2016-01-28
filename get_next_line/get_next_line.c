/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpressen <mpressen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/24 21:52:59 by mpressen          #+#    #+#             */
/*   Updated: 2016/01/28 07:54:39 by mpressen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static void			create_link(int fd, t_linked_list *begin_list, t_linked_list **addr_list)
{
	if (!(*addr_list = (t_linked_list*)malloc(sizeof(**addr_list))))
		return;
	(*addr_list)->fd = fd;
	(*addr_list)->str = NULL;
	(*addr_list)->prev = NULL;
	(*addr_list)->next = begin_list ;
}

static int			get_str_stocked(t_linked_list **addr_list, char **line)
{						
	int				i;
	int				start;

	i = 0;
	while ((*addr_list)->str[i] && (*addr_list)->str[i] == '\n') 
		i++;
	start = i;
	while ((*addr_list)->str[i] && (*addr_list)->str[i] != '\n')
		i++;
	*line = ft_strsub((*addr_list)->str, start, i - start);
	if ((*addr_list)->str[i + 1])
	{
		start = i;
		while ((*addr_list)->str[i])
			i++;
		(*addr_list)->str = ft_strsub((*addr_list)->str, start, i - start);
	}
	else
		ft_strdel(&((*addr_list)->str));
	return (1);
}

int					get_next_line(int const fd, char **line)
{
    static t_linked_list	*begin_list = NULL;
	t_linked_list			*list;
	int						ret;
	char					*buf;

	if (fd < 0 || !line)
        return (-1);
	list = begin_list;
	while (list && list->fd != fd)
		list = list->next;
	if (list)
		return (get_str_stocked(&list, line));
	else
	{
		create_link(fd, begin_list, &list);
		begin_list = list;
		buf = ft_memalloc(BUFF_SIZE + 1);
		list->str = ft_strnew(0);
		while ((ret = read(fd, buf, BUFF_SIZE)) > 0)
			list->str = ft_strjoin(list->str, buf);
		ft_strdel(&buf);
		if (list->str)
			return (get_str_stocked(&list, line));
		if (ret == -1)
			return (-1);
		else
			return (0);
	}
}
