/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpressen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/01 01:38:39 by mpressen          #+#    #+#             */
/*   Updated: 2016/01/31 08:26:03 by mpressen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** The ft_strncmp() function lexicographically compares
** the null-terminated strings s1 and s2.
** The function compares not more than n characters.
** The ft_strncmp() returns an integer greater than, equal to, or
** less than 0, according as the string s1 is greater than, equal to,
** or less than the string s2.
** The comparison is done using unsigned characters,
** so that `\200' is greater than `\0'.
*/

int		ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t			len1;
	size_t			len2;

	len1 = ft_strlen(s1);
	len2 = ft_strlen(s2);
	if (len1 < n && len2 < n)
	{
		if (len1 > len2)
			n = len1;
		else
			n = len2;
	}
	return (ft_memcmp((const void*)s1, (const void*)s2, n));
}
