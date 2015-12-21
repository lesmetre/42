/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_factoriel.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpressen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/26 23:10:07 by mpressen          #+#    #+#             */
/*   Updated: 2015/11/26 23:36:01 by mpressen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int		ft_iterative_factorial(int nb)
{
	int i;

	i = 0;
	if (nb >= 0 && nb <= 12)
	{
		i++;
		while (nb - 1 >= 0)
		{
			i *= nb;
			nb--;
		}
	}
	return(i);
}

int		main(void)
	{
		printf("%d\n", ft_iterative_factorial(1));
		return (0);
	}
