/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpressen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/02 00:30:22 by mpressen          #+#    #+#             */
/*   Updated: 2015/12/02 01:39:34 by mpressen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

size_t	ft_strbitssplit(char *s, char c)
{
	size_t	is_bit;
	size_t	bits;

	is_bit = 0;
	bits = 0;
	while (*s)
	{
		if (*s == c && is_bit == 0)
			s++;
		if (*s == c && is_bit == 1)
		{
			s++;
			is_bit = 0;
			bits++;
		}
		else
		{
			is_bit = 1;
			s++;
		}
	}
	if (*(s - 1) != c)
		bits++;
	return (bits);
}

size_t	ft_strlensplit(char *s, char c)
{
	size_t len;

	len = 0;
	while (*s)
	{
		if (*s == c)
			s++;
		else
		{
			len++;
			s++;
		}
	}
	return (len);
}

char	**ft_strsplit(char const *s, char c)
{
	char	**split;
	char	*s1;
	size_t	countbit;
	size_t	bits;

	s1 = (char *)s;
	bits = ft_strbitssplit(s1, c);
	countbit = 0;
	split = (char **)malloc(sizeof(**split) * (ft_strlensplit(s1, c) + bits));
	if (split)
	{
		while (countbit < bits)
		{
			while (*s1 == c)
				s1++;
			while (*s1 != c)
				*split[countbit]++ = *s1++;
			*(split[countbit]) = '\0';
			countbit++;
		}
		return (split);
	}
	return (NULL);
}
