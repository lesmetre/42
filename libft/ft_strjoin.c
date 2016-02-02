/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpressen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/01 23:38:30 by mpressen          #+#    #+#             */
/*   Updated: 2016/02/02 18:13:55 by mpressen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

/*
** The ft_strjoin() allocates and return a '\0' terminated string,
** result of the concatenation of s1 and s2.
** If allocation fails, the function returns NULL.
*/

char		*ft_strjoin(char const *s1, char const *s2)
{
	size_t	i;
	size_t	j;
	char	*join;

	i = -1;
	j = -1;
	if (!s1 && !s2)
	{
		ft_error_null("ft_strjoin");
		return (NULL);
	}
	if (!s1)
		return ((char*)s2);
	if (!s2)
		return ((char*)s1);
	if ((join = ft_strnew(ft_strlen(s1) + ft_strlen(s2))))
	{
		while (s1[++i])
			join[i] = s1[i];
		while (s2[++j])
			join[i++] = s2[j];
		join[i] = '\0';
		return (join);
	}
	return (NULL);
}
