/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpressen <mpressen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/24 21:52:59 by mpressen          #+#    #+#             */
/*   Updated: 2016/01/30 03:44:34 by mpressen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static void	create_link(int fd, t_linked_list *first, t_linked_list **list)
{
	if (!(*list = (t_linked_list*)malloc(sizeof(**list))))
		return ;
	(*list)->fd = fd;
	(*list)->str = NULL;
	(*list)->prev = NULL;
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
	if (!(*list) || !((*list)->str))
	{
		ft_strdel(line);
		return (0);
	}
	start = 0;
	while ((*list)->str[i] && (*list)->str[i] != '\n')
		i++;
	tmp = ft_strsub((*list)->str, 0, i);
	*line = ft_strdup(tmp);
	ft_strdel(&tmp);
	if ((*list)->str[i] && (*list)->str[++i])
	{
		start = i;
		while ((*list)->str[i])
			i++;
		tmp = ft_strsub((*list)->str, start, i - start);
	}
	ft_strdel(&((*list)->str));
	if (tmp)
	{
		(*list)->str = ft_strdup(tmp);
		ft_strdel(&tmp);
	}
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
		list->str = ft_strdup(tmp);
		ft_strdel(&tmp);
		ft_bzero(buf, BUFF_SIZE + 1);
		if (is_line(list->str))
			break ;
	}
	ft_strdel(&buf);
	if (ret == -1)
		return (-1);
	return (get_line_stocked(&list, line));
}
