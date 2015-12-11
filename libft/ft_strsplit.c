/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpressen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/02 00:30:22 by mpressen          #+#    #+#             */
/*   Updated: 2015/12/11 01:55:13 by mpressen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

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
