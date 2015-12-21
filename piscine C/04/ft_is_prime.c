/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_prime.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpressen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/27 00:56:58 by mpressen          #+#    #+#             */
/*   Updated: 2015/11/27 01:12:25 by mpressen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int		ft_is_prime2(int nb, int diviseur)
{
	if (diviseur >= nb / 2)
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

int		main(void)
{
	printf("%d\n", ft_is_prime(2147483647));
	return (0);
}
