/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpressen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/02 00:30:22 by mpressen          #+#    #+#             */
/*   Updated: 2016/01/31 09:29:52 by mpressen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

/*
** The ft_strsplit() allocates and returns an array of '\0' terminated strings,
** portions of the string s cut by the c character.
** If allocation fails, the function returns NULL.
*/

static char	**ft_strsplit2(char const *s, char c, char **split)
{
	size_t	start;
	size_t	end;
	size_t	i;
	size_t	bits;

	i = 0;
	bits = 0;
	while (s[i])
	{
		while (s[i] && s[i] == c)
			i++;
		start = i;
		while (s[i] && s[i] != c)
			i++;
		end = i;
		if (end != start)
			split[bits++] = ft_strsub(s, start, end - start);
	}
	split[bits] = NULL;
	return (split);
}

char		**ft_strsplit(char const *s, char c)
{
	char	**split;

	if (!s)
	{
		ft_error_null("ft_strsplit");
		return (NULL);
	}
	if ((split = (char**)malloc(sizeof(*split) * (ft_countbits(s, c) + 1))))
		return (ft_strsplit2(s, c, split));
	ft_error_malloc("ft_strsplit");
	return (NULL);
}
