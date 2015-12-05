/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpressen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/05 00:49:41 by mpressen          #+#    #+#             */
/*   Updated: 2015/12/05 01:04:20 by mpressen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strmapi(char const *s, char (*f) (unsigned int, char))
{
	char			*s1;
	char			*str;
	unsigned int	i;

	s1 = (char *)s;
	i = 0;
	if (s1 && f)
	{
		str = (char *)malloc(sizeof(*str) * (ft_strlen(s1) + 1));
		if (str)
		{
			while (*s1)
				*str = f(i++, *s1++);
			*str = '\0';
			return (str);
		}
	}
	return (NULL);
}
