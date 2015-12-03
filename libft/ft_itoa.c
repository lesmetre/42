/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpressen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/02 02:42:22 by mpressen          #+#    #+#             */
/*   Updated: 2015/12/02 04:48:38 by mpressen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>
#include <stdio.h>

int		ft_itoa_len(int n)
{
	int		len;

	len = 1;
	if (n < 0)
	{
		n *= -1;
		len++;
	}
	while (n > 1)
	{
		n /= 10;
		len++;
	}
	return (len);
}

char	*ft_itoa(int n)
{
	char	*str;
	int		len;
	int		tmpn;

	tmpn = n;
	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	len = ft_itoa_len(n);
	str = (char *)malloc(sizeof(*str) * len);
	if (str)
	{
		str[len] = '\0';
		if (n < 0)
			tmpn *= -1;
		while (len--)
		{
			str[len] = tmpn % 10 + '0';
			tmpn /= 10;
		}
		if (n < 0)
			str[0] = '-';
		return (str);
	}
	return (NULL);
}
