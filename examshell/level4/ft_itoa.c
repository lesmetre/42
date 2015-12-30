/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpressen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/18 19:20:00 by mpressen          #+#    #+#             */
/*   Updated: 2015/12/19 13:26:07 by mpressen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		ft_strlen(char *str)
{
	int i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_strdup(char *str)
{
	char	*dst;
	int		i;

	i = -1;
	dst = (char *)malloc(sizeof(*dst) * ft_strlen(str) + 1);
	while (str[++i])
		dst[i] = str[i];
	dst[i] = '\0';
	return (dst);
}

char	*ft_itoa(int nbr)
{
	int		i;
	char	*str;
	int		tmp;
	int		negative;

	i = 1;
	negative = 0;
	if (nbr == -2147483648)
		return (ft_strdup("-2147483648"));
	if (nbr < 0)
	{
		negative = 1;
		nbr = -nbr;
	}
	tmp = nbr;
	while (tmp > 9)
	{
		tmp /= 10;
		i++;
	}
	tmp = nbr;
	if ((str = (char *)malloc(sizeof(*str) * i + negative + 1)))
	{
		str[i + negative] = '\0';
		while (i--)
		{
			str[i + negative] = '0' + tmp % 10;
			tmp /= 10;
		}
		if (negative == 1)
			str[0] = '-';
		return (str);
	}
	return (0);
}
