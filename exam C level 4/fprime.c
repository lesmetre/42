/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fprime.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpressen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/21 12:25:34 by mpressen          #+#    #+#             */
/*   Updated: 2015/12/21 12:46:40 by mpressen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>

void	fprime(int c)
{
	int i;

	i = 2;
	if (c == 1 || c == 0)
			printf("%d", c);
	while (c != 1)
	{
		if (c % i == 0)
		{
			c /= i;
			printf("%d", i);
			if (c != 1)
				printf("%c", '*');
		}
		else
			i++;
	}
}

int		main(int ac, char **av)
{
	if (ac == 2)
		fprime(atoi(av[1]));
	printf("\n");
	return (0);
}
