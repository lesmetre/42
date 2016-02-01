/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpressen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/02 02:42:22 by mpressen          #+#    #+#             */
/*   Updated: 2016/02/01 21:56:32 by mpressen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

static int		ft_strlen(char *s)
{
    int  i;

    i = 0;
    while (s[i])
        i++;
    return (i);
}

static char    *ft_strdup(char *s1)
{
    char    *dup;
    int     i;

    i = -1;
    if ((dup = (char*)malloc(sizeof(ft_strlen(s1) + 1))))
    {
        while (s1[++i])
            dup[i] = s1[i];
        dup[i] = '\0';
        return (dup);
    }
    return (NULL);
}

static int		ft_itoa_base_len(int value, int base)
{
	int		len;

	len = 1;
	if (value < 0)
	{
		value *= -1;
		if (base == 10)
			len++;
	}
	while (value > base - 1)
	{
		value /= base;
		len++;
	}
	return (len);
}

char			*ft_itoa_base(int value, int base)
{
	char	*str;
	int		len;

	if (base < 2 || base > 16)
		return (NULL);
	if (value == -2147483648)
	{
		if (base == 10)
			return (ft_strdup("-2147483648"));
		else
			return (NULL);
	}
	len = ft_itoa_base_len(value, base);
	if ((str = (char*)malloc(sizeof(*str * len + 1))))
	{
		str[len] = '\0';
		while (len--)
		{
			if (value % base < 10)
				str[len] = value % base + '0';
			else
				str[len] = value % base + 'A' - 10;
			value /= base;
		}
		if (value < 0 && base == 10)
			str[0] = '-';
		return (str);
	}
	return (NULL);
}
