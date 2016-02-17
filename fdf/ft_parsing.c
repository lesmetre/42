/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parsing.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpressen <mpressen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/10 16:37:38 by mpressen          #+#    #+#             */
/*   Updated: 2016/02/17 13:02:31 by mpressen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static int		ft_error(int error, char *str)
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

static void		create_new_elem(int y, int x, int z, t_fdf **param)
{
	t_fdf	*new;

	if (!(new = (t_fdf*)malloc(sizeof(*new))))
	{
		ft_error_malloc("create_new_elem");
		exit(1);
	}
	new->x = x;
	new->y = y;
	new->z = z;
	new->next = *param;
	*param = new;
}

static void		create_list(t_fdf **param, int *int_tab, int y, size_t ref)
{
	size_t	x;

	x = -1;
	while (++x < ref)
		create_new_elem(y, x, int_tab[x], param);
}

static int		check_fd_init_param(char *line, int y, t_fdf **param)
{
	int				i;
	static size_t	ref = 0;
	char			**tab;
	int				*int_tab;

	i = -1;
	tab = ft_strsplit(line, ' ');
	if (!(int_tab = (int*)malloc(sizeof(int_tab) * ft_indexlen((void**)tab))))
		ft_error_malloc("check_fd_init_program");
	while (tab[++i])
		int_tab[i] = ft_atoi(tab[i]);
	if (!ref)
		ref = ft_indexlen((void**)tab);
	else if (ref > ft_indexlen((void**)tab))
		return (1);
	create_list(param, int_tab, y, ref);
	free_tab(&tab);
	ft_memdel((void**)&int_tab);
	return (0);
}

int				ft_parsing(int ac, char **av, t_fdf **param)
{
	char	*line;
	int		fd;
	int		ret;
	int		y;

	line = NULL;
	y = 0;
	if (ac != 2)
		return (ft_error(1, NULL));
	if ((fd = open(av[1], O_RDONLY)) == -1)
		return (ft_error(2, av[1]));
	while ((ret = get_next_line(fd, &line)))
	{
		if (check_fd_init_param(line, y, param))
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
