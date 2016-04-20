/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parsing.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpressen <mpressen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/10 16:37:38 by mpressen          #+#    #+#             */
/*   Updated: 2016/04/20 11:59:47 by mpressen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static int	ft_error(int error, char *str)
{
	if (error == 1)
		ft_putendl_fd("Usage : ./fdf <filename> [ case_size z_size ]", 2);
	else if (error == 2)
	{
		ft_putstr_fd("no file ", 2);
		ft_putstr_fd(str, 2);
		ft_putstr_fd("\n", 2);
	}
	else if (error == 3)
		ft_putendl_fd("Found wrong line length. Exiting.", 2);
	else if (error == 4)
		ft_putendl_fd("No data found.", 2);
	return (1);
}

static void	create_new_elem(size_t x, size_t y, int z, t_fdflist **list, int color)
{
	t_fdflist	*new;

	if (!(new = (t_fdflist*)malloc(sizeof(*new))))
	{
		ft_error_malloc("create_new_elem");
		exit(1);
	}
	new->x = x;
	new->y = y;
	new->z = z;
	new->color = color;
	new->next = *list;
	*list = new;
}

static void	create_list(t_fdflist **list, int *int_tab, size_t y, size_t ref, int *color)
{
	size_t	x;

	x = -1;
	while (++x < ref)
		create_new_elem(x, y, int_tab[x], list, color[x]);
}

int     ft_atoi_hexa(const char *str)
{
    size_t  i;
    int     res;

    i = 1;
    res = 0;
    while (str[++i])
	{
		if (ft_isdigit(str[i]))
			res = res * 16 + str[i] - '0';
		else
			res = res * 16 + str[i] - 'a' + 10;
	}
    return (res);
}

static int	check_fd_init_param(char *line, size_t y, t_fdflist **list)
{
	size_t			i;
	static size_t	ref = 0;
	char			**tab;
	int				*int_tab;
	int				*color;
	char			*tmp;

	i = -1;
	tab = ft_strsplit(line, ' ');
	if (!(int_tab = (int*)malloc(sizeof(int_tab) * ft_indexlen((void**)tab))))
		ft_error_malloc("check_fd_init_program");
	if (!(color = (int*)malloc(sizeof(color) * ft_indexlen((void**)tab))))
		ft_error_malloc("check_fd_init_program");
	while (tab[++i])
	{
		int_tab[i] = ft_atoi(tab[i]);
		if ((tmp = ft_strchr(tab[i], ',')))
			color[i] = ft_atoi_hexa(tmp + 1);
		else
			color[i] = 0;
	}
	if (!ref)
		ref = ft_indexlen((void**)tab);
	else if (ref > ft_indexlen((void**)tab))
		return (1);
	create_list(list, int_tab, y, ref, color);
	free_tab(&tab);
	ft_memdel((void**)&int_tab);
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
