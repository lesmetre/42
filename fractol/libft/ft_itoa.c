/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpressen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/02 02:42:22 by mpressen          #+#    #+#             */
/*   Updated: 2016/01/31 10:22:21 by mpressen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

/*
** The ft_itoa() allocates and returns a '\0' terminated string,
** representing the integer n.
** Negatives integers must be handled.
** If allocation fails, the function returns NULL.
*/

static int		ft_itoa_len(int n)
{
	int		len;

	len = 1;
	if (n < 0)
	{
		n *= -1;
		len++;
	}
	while (n > 9)
	{
		n /= 10;
		len++;
	}
	return (len);
}

char			*ft_itoa(int n)
{
	char	*str;
	int		len;
	int		tmp;

	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	tmp = n;
	len = ft_itoa_len(n);
	if ((str = ft_strnew(len)))
	{
		if (n < 0)
			tmp *= -1;
		while (len--)
		{
			str[len] = tmp % 10 + '0';
			tmp /= 10;
		}
		if (n < 0)
			str[0] = '-';
		return (str);
	}
	ft_error_malloc("ft_itoa");
	return (NULL);
}
