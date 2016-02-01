/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   brainfuck.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpressen <mpressen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/31 17:13:18 by mpressen          #+#    #+#             */
/*   Updated: 2016/02/01 16:08:12 by mpressen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>

int		main(int ac, char **av)
{
	char	*ptr;
	int		i;
	int		j;

	i = -1;
	ac = (char)ac;
	if (av[1] && av[1][0])
	{
		if (!(ptr = (char*)malloc(sizeof(*ptr) * 2048)))
			return (1);
		while (++i < 2048)
			ptr[i] = '\0';
		i = -1;
		while (av[1][++i])
		{
			if (av[1][i] == '>')
				ptr++;
			if (av[1][i] == '<')
				ptr--;
			if (av[1][i] == '+')
				(*ptr)++;
			if (av[1][i] == '-')
				(*ptr)--;
			if (av[1][i] == '[' && (!(*ptr)))
			{
				j = 0;
				i++;
				while (av[1][i])
				{
					if (av[1][i] == '[')
						j++;
					if (av[1][i] == ']')
					{
						if (j == 0)
							break ;
						else
							j--;
					}
					i++;
				}
			}
			if (av[1][i] == ']' && (*ptr))
			{
				j = 0;
				i--;
				while (i > -1)
				{
					if (av[1][i] == ']')
						j++;
					if (av[1][i] == '[')
					{
						if (j == 0)
							break ;
						else
							j--;
					}
					i--;
				}
			}
			if (av[1][i] == '.')
				write(1, ptr, 1);
		}
	}
	return (0);
}
