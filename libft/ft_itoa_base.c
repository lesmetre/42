/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpressen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/02 02:42:22 by mpressen          #+#    #+#             */
/*   Updated: 2016/02/02 13:12:59 by mpressen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** The ft_itoa_base() allocates and returns a '\0' terminated string,
** representing the integer value in the base set as parameter.
** Base must be an integer between 2 and 16,
** and characters representing base are 0123456789ABCDEF.
** Negatives integers must be handled onlu for base 10.
** If allocation fails, the function returns NULL.
*/

static int		ft_itoa_base_len(int value, int base)
{
	int		i;

	i = 1;
	while (value > base - 1)
	{
		i++;
		value /= base;
	}
	return (i);
}

char			*ft_itoa_base(int value, int base)
{
	char	*str;
	int		len;
	int		sign;

	sign = 0;
	if (base < 2 || base > 16)
		return (NULL);
	if (value == -2147483648)
		return (base == 10 ? ft_strdup("-2147483648") : NULL);
	sign = ((value < 0 && base == 10) ? 1 : 0);
	value > 0 ? value : (value *= -1);
	len = ft_itoa_base_len(value, base) + sign;
	if (!(str = ft_strnew(len)))
	{
		ft_error_malloc("ft_itoa_base");
		return (NULL);
	}
	while (len--)
	{
		str[len] = value % base + (value % base < 10 ? '0' : 'A' - 10);
		value /= base;
	}
	str[0] = (sign ? '-' : str[0]);
	return (str);
}
