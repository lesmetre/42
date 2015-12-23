/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpressen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/23 20:01:13 by mpressen          #+#    #+#             */
/*   Updated: 2015/12/23 23:01:27 by mpressen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

void	ft_putchar(char c)
{
    write(1, &c, 1);
}

void	print_tab(char **tab)
{
    int	l;
    int	c;

    l = -1;
    while (tab[++l])
    {
        c = -1;
        while (tab[l][++c])
        {
            ft_putchar(tab[l][c]);
            ft_putchar(' ');
        }
        ft_putchar('\n');
    }
}

int		main(int ac, char **av)
{
	int		line;
	int		column;
	char	**tab;

	line = 0;
	if (ac == 10)
	{
		while (av[++line])
		{
			column = 0;
			while ((av[line][column] >= '0' && av[line][column] <= '9') || av[line][column] == '.')
				column++;
			if (column != 9)
			{
				printf("erreur\n");
				return (0);
			}
		}
		if ((tab = (char **)malloc(sizeof(*tab) * 10)))
		{
			line = -1;
			while (++line < 9)
			{
				if ((tab[line] = (char *)malloc(sizeof(**tab) * 10)))
				{
					column = -1;
					while (++column < 9)
						tab[line][column] = av[line + 1][column];
					tab[line][column] = '\0';
				}
				else
					tab[line] = NULL;
			}
			tab[line] = 0;
		}
		print_tab(tab);
	}
	else
		printf("erreur\n");
	return (0);
}
