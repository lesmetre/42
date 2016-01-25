/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpressen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/01 23:52:02 by mpressen          #+#    #+#             */
/*   Updated: 2016/01/25 05:54:41 by mpressen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

/*
** The ft_strtrim() allocates and returns a string's copy,
** but without the white spaces at the beginning and the end of the string.
** ' ', '\n' and '\t' are the white spaces considerated.
** If allocation fails, the function returns NULL.
*/

static char	*ft_strtrim2(char const *s, size_t i, size_t j, size_t begin)
{
	char	*trim;
	size_t	len;

	if (!(s))
		return (ft_error_null("ft_strtrim"));
	len = ft_strlentrim(s);
	if ((trim = (char *)malloc(sizeof(*trim) * (len + 1))))
	{
		while (j < len)
		{
			while (ft_isspace((int)s[i]) && begin == 1)
				i++;
			begin = 0;
			trim[j++] = s[i++];
		}
		trim[j] = '\0';
		return (trim);
	}
	return (ft_error_malloc("ft_strtrim"));
}

char		*ft_strtrim(char const *s)
{
	size_t	i;
	size_t	j;
	size_t	begin;

	begin = 1;
	i = 0;
	j = 0;
	return (ft_strtrim2(s, i, j, begin));
}
