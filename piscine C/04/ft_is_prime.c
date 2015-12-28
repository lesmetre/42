/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_prime.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpressen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/27 00:56:58 by mpressen          #+#    #+#             */
/*   Updated: 2015/12/21 20:20:11 by mpressen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>

/*
int		ft_is_prime2(int nb, int diviseur)
{
	if (diviseur > nb / 2)
		return (1);
	if (nb % diviseur == 0)
		return (0);
	else
		return (ft_is_prime2(nb, diviseur + 2));
}

int		ft_is_prime(int nb)
{
	int diviseur;

	diviseur = 3;
	if (nb == 0 || nb == 1 || nb % 2 == 0)
		return (0);
	else
		return (ft_is_prime2(nb, diviseur));
}
*/

int		ft_square(int nb)
{
	int i;

	i = 1;
	while ((i * i) < nb)
		i++;
	return (i);
}

int		ft_is_prime(int nb)
{
	int i;
	int square;

	square = ft_square(nb);
	i = 3;
	if (nb == 0 || nb == 1 || nb % 2 == 0)
		return (0);
	while (nb % i != 0 && i <= square)
		i = i + 2;
	if (i >= square)
		return (1);
	return (0);
}


int		main(int ac, char **av)
{
	if (ac == 2)
		printf("%d\n", ft_is_prime(atoi(av[1])));
	return (0);
}
