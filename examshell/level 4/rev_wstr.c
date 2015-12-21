/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rev_wstr.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: exam <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/15 12:33:30 by exam              #+#    #+#             */
/*   Updated: 2015/12/15 19:56:31 by mpressen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>

void	ft_putstr(char *str)
{
	while (*str)
		write(1, str++, 1);
}

int		ft_strlen(char *str)
{
	int i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_strsub(char *str, int start, int size)
{
	char	*sub;
	int		i;

	i = 0;
	sub = (char *)malloc(sizeof(*sub) * (size + 1));
	if (sub)
	{
		while (i < size)
		{
			sub[i] = str[start + i];
			i++;
		}
		sub[i] = '\0';
		return (sub);
	}
	return ((char*)0);
}

int		ft_isspace(int c)
{
	if (c == ' ' || c == '\t')
		return (1);
	return (0);
}

int		main(int ac, char **av)
{
	char	**tab;
	int		i;
	int		j;
	int		start;
	int		end;

	tab = 0;
	i = 0;
	j = 0;
	if (ac == 2)
	{
		tab = (char **)malloc(sizeof(*tab) * (ft_strlen(av[1]) / 2 + 2));
		if (tab)
		{
			while (av[1][i])
			{
				start = i;
				while (av[1][i] && !(ft_isspace(av[1][i])))
					i++;
				end = i;
				tab[j] = ft_strsub(av[1], start, (end - start));
				j++;
				if (av[1][i])
					i++;
			}
			tab[j] = 0;
			while (--j >= 0)
			{
				ft_putstr(tab[j]);
				free(tab[j]);
				if (j != 0)
					ft_putstr(" ");
			}
			free(tab);
		}
	}
	ft_putstr("\n");
	return (0);
}
