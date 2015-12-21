/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sqrt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpressen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/27 00:37:03 by mpressen          #+#    #+#             */
/*   Updated: 2015/11/27 00:54:35 by mpressen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int		ft_sqrt2(int nb, int tmp)
{
	if (tmp >= nb / 2)
		return (0);
	if (nb == tmp * tmp)
		return (tmp);
	return (0 + ft_sqrt2(nb, tmp + 1));
}

int		ft_sqrt(int nb)
{
	int tmp;

	tmp = 1;
	return (ft_sqrt2(nb, tmp));
}
int		main(void)
{
	printf("%d\n", ft_sqrt(9));
	return (0);
}
