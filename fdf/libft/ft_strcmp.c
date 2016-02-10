/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpressen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/01 01:38:39 by mpressen          #+#    #+#             */
/*   Updated: 2016/01/30 09:18:30 by mpressen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** The ft_strcmp() function lexicographically compares
** the null-terminated strings s1 and s2.
** The function returns an integer greater than, equal to,
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
	n = (s1len >= s2len ? s1len : s2len);
	return (ft_memcmp(s1, s2, n));
}
