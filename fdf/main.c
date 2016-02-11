/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpressen <mpressen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/10 16:37:38 by mpressen          #+#    #+#             */
/*   Updated: 2016/02/11 01:58:11 by mpressen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "fdf.h"

int		main(int ac, char **av)
{
	char	*line;
	int		fd;
	int		ret;
	int		i;
	int		ref_index;
	int		tmp_index;

	ref_index = 0;
	line = NULL;
	if (ac != 2)
	{
		ft_putendl_fd("Usage : ./fdf <filename> [ case_size z_size ]", 2);
		return (1);
	}
	if ((fd = open(av[1], O_RDONLY)) == -1)
	{
		ft_putstr_fd("no file ", 2);
		ft_putstr_fd(av[1], 2);
		ft_putstr_fd("\n", 2);
		return (1);
	}
	while ((ret = get_next_line(fd, &line)))
	{
//		ft_putendl(line);
		i = -1;
		while (line[++i])
			if (!(ft_isdigit(line[i])) && line[i] != ' ' && line[i] != '-')
			{
//				ft_putendl("on rencontre un caractere inutile");
				line[i] = ' ';
			}
//		ft_putendl(line);
//		ft_putnbr(ft_indexlen((void**)ft_strsplit(line, ' ')));
		if (!ref_index)
			ref_index = ft_indexlen((void**)ft_strsplit(line, ' '));
		tmp_index = ft_indexlen((void**)ft_strsplit(line, ' '));
		if (tmp_index != ref_index)
		{
			ft_putendl_fd("Found wrong line length. Exiting.", 2);
			return (1);
		}
//		ft_putstr("\n");
	}
	if (!ret && !line)
	{
		ft_putendl_fd("No data found.", 2);
		return (1);
	}
	ft_strdel(&line);
	if (close(fd))
		return (1);
	ft_putendl("good file.");
	return (0);
}
