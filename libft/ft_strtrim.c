/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpressen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/01 23:52:02 by mpressen          #+#    #+#             */
/*   Updated: 2016/02/03 21:17:35 by mpressen         ###   ########.fr       */
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

char	*ft_strtrim(char const *s)
{
	size_t	i;
	size_t	start;
	size_t	len;

	i = 0;
	len = ft_strlen(s);
	if (!(s))
	{
		ft_error_null("ft_strtrim");
		return (NULL);
	}
	while (ft_isspace((int)s[i]))
		i++;
	if (i == len)
		return (ft_strdup(""));
	start = i;
	i = len - 1;
	while (ft_isspace((int)s[i]))
		i--;
	return (ft_strsub(s, start, i + 1 - start));
	return (NULL);
}
