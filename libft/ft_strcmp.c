/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpressen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/01 01:38:39 by mpressen          #+#    #+#             */
/*   Updated: 2016/01/25 03:16:36 by mpressen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** The strcmp() function lexicographically compare
** the null-terminated strings s1 and s2.
** The strcmp() function return an integer greater than, equal to,
** or less than 0, according as the string s1 is greater than, equal to,
** or less than the string s2. The comparison is done using unsigned characters,
** so that `\200' is greater than `\0'.
*/

int		ft_strcmp(const char *s1, const char *s2)
{
	int s1len;
	int s2len;
	int n;

	s1len = ft_strlen(s1);
	s2len = ft_strlen(s2);
	if (s1len >= s2len)
		n = s1len;
	else
		n = s2len;
	return (ft_memcmp(s1, s2, n));
}
