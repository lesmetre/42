/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpressen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/09 01:10:48 by mpressen          #+#    #+#             */
/*   Updated: 2015/12/09 01:32:04 by mpressen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>

int		*ft_range(int min, int max)
{
	int	*tab;
	int i;

	i = -1;
	if (min >= max)
		return ((int *)0);
	tab = (int *)malloc(sizeof(*tab) * (max - min));
	if (tab)
	{
		while (min < max)
		{
			tab[++i] = min++;
			printf("%d\n", tab[i]);
		}
		return (tab);
	}
	return ((int *)0);
}

int		main(void)
{
	printf("%s\n", ft_range(8, 8));
	return (0);
}
