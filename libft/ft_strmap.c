/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpressen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/05 00:38:44 by mpressen          #+#    #+#             */
/*   Updated: 2015/12/05 01:03:10 by mpressen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strmap(char const *s, char (*f)(char))
{
	char *str;

	if (s && f)
	{
		str = (char *)malloc(sizeof(*str) * (ft_strlen(s) + 1));
		if (str)
		{
			while (*s)
				*str++ = f(*s++);
			*str = '\0';
			return (str);
		}
	}
	return (NULL);
}
