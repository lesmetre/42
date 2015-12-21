/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpressen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/09 01:10:48 by mpressen          #+#    #+#             */
/*   Updated: 2015/12/09 03:08:36 by mpressen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>

int		ft_ultimate_range(int **range, int min, int max)
{
	int i;
	int *tab;

	i = 0;
	tab = (int *)malloc(sizeof(*tab) * (max - min));
	if (tab)
	{
		while (min < max)
		{
			tab[i] = min++;
			printf("%d\n", tab[i]);
			i++;
		}
		*range = tab;
		return (i);
	}
	*range = (void *)0;
	return (0);	
}

int		main(void)
{
	int	**range;

	range = (int **)malloc(sizeof(*range) * 1);
	printf("%d\n", ft_ultimate_range(range, 9, 8));
	return (0);
}
