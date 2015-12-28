/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_next_prime.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpressen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/27 01:51:46 by mpressen          #+#    #+#             */
/*   Updated: 2015/12/21 19:38:27 by mpressen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int		ft_find_next_prime(int nb)
{
	int i;

	while (1)
	{
		i = 2;
		while ( nb % i != 0)
			i++;
		if (i == nb)
			return (nb);
		else
			nb++;
	}
	return (0);
}

int		main(void)
{
	printf("%d\n", ft_find_next_prime(3));
	return (0);
}
