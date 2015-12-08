/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpressen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/02 00:30:22 by mpressen          #+#    #+#             */
/*   Updated: 2015/12/08 05:48:58 by mpressen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

size_t	ft_bits(const char *s, char c)
{
	size_t	is_bit;
	size_t	bits;
	size_t	i;

	i = 0;
	is_bit = 0;
	bits = 0;
	while (s[i])
	{
		if (s[i] == c && is_bit != 0)
			is_bit = 0;
		if (s[i] != c && is_bit == 0)
		{
			bits++;
			is_bit = 1;
		}
		while (s[i] && s[i] == c && is_bit == 0)
			i++;
		while (s[i] && s[i] != c && is_bit != 0)
			i++;
	}
	return (bits);
}

char	**ft_strsplit(char const *s, char c)
{
	char	**split;
	size_t	i;
	size_t	start;
	size_t	end;
	size_t	bits;

	bits = 0;
	i = 0;
	if (s && (split = (char **)malloc(sizeof(*split) * (ft_bits(s, c) + 1))))
	{
		while (s[i])
		{
			while (s[i] && s[i] == c)
				i++;
			start = i;
			while (s[i] && s[i] != c)
				i++;
			end = i;
			if (end > start)
				split[bits++] = ft_strsub(s, start, end - start);
		}
		split[bits] = NULL;
		return (split);
	}
	return (NULL);
}
