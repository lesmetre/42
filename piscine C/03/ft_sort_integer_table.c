/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_integer_table.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpressen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/26 22:18:40 by mpressen          #+#    #+#             */
/*   Updated: 2015/11/26 22:39:35 by mpressen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

void	ft_sort_integer_table(int *tab, int size)
{
	int count;
	int tmp;

	count = 0;
	while (count <= size - 1)
	{
		printf("%d", tab[count]);
		if (tab[count] > tab [count + 1])
		{
			tmp = tab[count];
			tab[count] = tab[count + 1];
			tab[count + 1] = tmp;
			count = 0;
		}
		else
			count++;
	}
}

int		main(void)
{
	int	tab[8] = {8, 9, 5, 7, 7, 5, 3, 1};
	int *ptr;

	ptr = &(tab[0]);
	ft_sort_integer_table(ptr, 8);
	return (0);
}
