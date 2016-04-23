/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpressen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/01 00:27:56 by mpressen          #+#    #+#             */
/*   Updated: 2016/01/30 09:15:36 by mpressen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** The ft_strchr() function locates the first occurrence of c
** in the string pointed to by s.
** The terminating null character is considered to be part of the string;
** therefore if c is `\0', the functions locate the terminating `\0'.
** The function returns a pointer to the located character,
** or NULL if the character does not appear in the string.
*/

char	*ft_strchr(const char *s, int c)
{
	int i;

	i = -1;
	while (s[++i])
		if (s[i] == (char)c)
			return ((char*)s + i);
	if (s[i] == (char)c)
		return ((char*)s + i);
	return (NULL);
}
