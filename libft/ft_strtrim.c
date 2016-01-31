/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpressen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/01 23:52:02 by mpressen          #+#    #+#             */
/*   Updated: 2016/01/31 10:08:32 by mpressen         ###   ########.fr       */
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

char		*ft_strtrim(char const *s)
{
	char	*trim;
	size_t	len;
	size_t	i;
	size_t	j;

	i = 0;
	j = -1;
	if (!(s))
	{
		ft_error_null("ft_strtrim");
		return (NULL);
	}
	len = ft_strlentrim(s);
	if ((trim = ft_strnew(len)))
	{
		while (ft_isspace((int)s[i]))
			i++;
		while (++j < len)
			trim[j] = s[i++];
		return (trim);
	}
	ft_error_malloc("ft_strtrim");
	return (NULL);
}
