/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpressen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/01 01:38:39 by mpressen          #+#    #+#             */
/*   Updated: 2016/01/25 20:03:17 by mpressen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** The strncmp() function lexicographically compares
** the null-terminated strings s1 and s2.
** The function compares not more than n characters.
** The strncmp() returns an integer greater than, equal to, or
** less than 0, according as the string s1 is greater than, equal to,
** or less than the string s2.
** The comparison is done using unsigned characters,
** so that `\200' is greater than `\0'.
*/

int		ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t			s1len;
	size_t			s2len;
	unsigned char	*s11;
	unsigned char	*s22;

	s11 = (unsigned char *)s1;
	s22 = (unsigned char *)s2;
	s1len = ft_strlen(s1);
	s2len = ft_strlen(s2);
	if (s1len < n && s2len < n)
	{
		if (s1len > s2len)
			n = s1len;
		else
			n = s2len;
	}
	return (ft_memcmp(s11, s22, n));
}
