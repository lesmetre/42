/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpressen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/01 23:17:46 by mpressen          #+#    #+#             */
/*   Updated: 2016/01/28 08:00:03 by mpressen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

/*
** The ft_strsub() allocates and returns a copy of a portion's string.
** The portion start at index start, with len as length.
** If allocation fails, the function return NULL.
*/

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char	*s1;
	char	*sub;
	size_t	count;

	count = 0;
	if (!(s))
		return (NULL);
	s1 = (char *)s;
	sub = (char *)malloc(sizeof(*sub) * (len + 1));
	if (sub)
	{
		while (count < len)
		{
			sub[count] = s1[start + count];
			count++;
		}
		sub[count] = '\0';
		return (sub);
	}
	return (NULL);
}
