/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpressen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/01 00:27:56 by mpressen          #+#    #+#             */
/*   Updated: 2016/01/31 08:48:23 by mpressen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** The ft_strrchr() function locates the last occurrence of c
** in the string pointed to by s.
** The terminating null character is considered to be part of the string;
** therefore if c is `\0', the functions locate the terminating `\0'.
** The function returns a pointer to the located character,
** or NULL if the character does not appear in the string.
*/

char	*ft_strrchr(const char *s, int c)
{
	size_t i;

	i = ft_strlen(s);
	if (s[i] == c)
		return ((char*)s + i);
	while (s[--i])
		if (s[i] == c)
			return ((char*)s + i);
	return (NULL);
}
