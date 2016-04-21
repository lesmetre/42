/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parsing.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpressen <mpressen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/10 16:37:38 by mpressen          #+#    #+#             */
/*   Updated: 2016/04/21 22:11:44 by mpressen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	create_new_elem(size_t x, size_t y,
		t_fdfparse parse, t_fdflist **list)
{
	t_fdflist	*new;

	if (!(new = (t_fdflist*)malloc(sizeof(*new))))
		exit(1);
	new->x = x;
	new->y = y;
	new->z = parse.int_tab[x];
	new->color = parse.color[x];
	new->next = *list;
	*list = new;
}

static void	create_list(t_fdflist **list,
		size_t y, size_t ref, t_fdfparse parse)
{
	size_t	x;

	x = -1;
	while (++x < ref)
		create_new_elem(x, y, parse, list);
}

static void	parse_parse(t_fdfparse *parse)
{
	size_t			i;
	char			*tmp;

	i = -1;
	while (parse->tab[++i])
	{
		parse->int_tab[i] = ft_atoi(parse->tab[i]);
		tmp = ft_strchr(parse->tab[i], ',');
		parse->color[i] = (tmp ? ft_atoi_hexa(tmp + 1) : -1);
	}
}

static int	check_fd_init_param(char *line, size_t y, t_fdflist **list)
{
	static size_t	ref = 0;
	t_fdfparse		parse;
	size_t			index;

	if (!(parse.tab = ft_strsplit(line, ' ')))
		exit(ft_error(4, NULL));
	index = ft_indexlen((void**)parse.tab);
	if (!(parse.int_tab = (int*)malloc(sizeof(int) * index))
		|| !(parse.color = (int*)malloc(sizeof(int) * index)))
		exit(1);
	parse_parse(&parse);
	if (!ref)
		ref = index;
	else if (ref > index)
		return (1);
	create_list(list, y, ref, parse);
	free_tab(&parse.tab);
	ft_memdel((void**)&parse.int_tab);
	ft_memdel((void**)&parse.color);
	return (0);
}

int			ft_parsing(int ac, char **av, t_fdflist **list)
{
	char	*line;
	int		fd;
	int		ret;
	size_t	y;

	line = NULL;
	y = 0;
	if (ac != 2)
		return (ft_error(1, NULL));
	if ((fd = open(av[1], O_RDONLY)) == -1)
		return (ft_error(2, av[1]));
	while ((ret = get_next_line(fd, &line)))
	{
		if (check_fd_init_param(line, y, list))
			return (ft_error(3, NULL));
		y++;
	}
	if (!line)
		return (ft_error(4, NULL));
	ft_strdel(&line);
	if (close(fd))
		return (1);
	return (0);
}
