/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpressen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/01 23:38:30 by mpressen          #+#    #+#             */
/*   Updated: 2016/02/03 20:01:48 by mpressen         ###   ########.fr       */
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
		return (ft_strdup(s2));
	if (!s2)
		return (ft_strdup(s1));
	if ((join = ft_strnew(ft_strlen(s1) + ft_strlen(s2))))
	{
		join = ft_strcpy(join, s1);
		join = ft_strcat(join, s2);
		return (join);
	}
	ft_error_malloc("ft_strjoin");
	return (NULL);
}
