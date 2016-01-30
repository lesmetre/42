/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpressen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/01 23:17:46 by mpressen          #+#    #+#             */
/*   Updated: 2016/01/30 01:55:32 by mpressen         ###   ########.fr       */
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
	size_t	i;

	i = -1;
	if (!(s))
		return (NULL);
	s1 = (char *)s;
	if ((sub = ft_memalloc(len + 1)))
	{
		while (++i < len)
			sub[i] = s1[start + i];
		sub[i] = '\0';
		return (sub);
	}
	return (NULL);
}
