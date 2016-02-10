/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpressen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/01 23:17:46 by mpressen          #+#    #+#             */
/*   Updated: 2016/01/31 09:36:37 by mpressen         ###   ########.fr       */
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
	char	*sub;
	size_t	i;

	i = -1;
	if (!s)
		return (NULL);
	if ((sub = ft_strnew(len)))
	{
		while (++i < len)
			sub[i] = s[start + i];
		return (sub);
	}
	return (NULL);
}
