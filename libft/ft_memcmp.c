/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpressen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/28 03:11:21 by mpressen          #+#    #+#             */
/*   Updated: 2016/01/30 08:51:05 by mpressen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** The ft_memcmp() function compares byte string s1 against byte string s2.
** Both strings are assumed to be n bytes long.
** The ft_memcmp() function returns zero if the two strings are identical,
** otherwise returns the difference between the first two differing bytes.
** Zero-length strings are always identical.
*/

int		ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char	*s11;
	unsigned char	*s22;
	size_t			i;

	if (n == 0)
		return (0);
	s11 = (unsigned char*)s1;
	s22 = (unsigned char*)s2;
	i = -1;
	while (++i < n)
		if (s11[i] != s22[i])
			return (s11[i] - s22[i]);
	return (0);
}
