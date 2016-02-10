/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpressen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/05 00:38:44 by mpressen          #+#    #+#             */
/*   Updated: 2016/01/31 08:15:57 by mpressen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

/*
** The ft_strmap() applies the function f to each character of the string,
** in order to allocate a new string, result of f's successives applies.
** The ft_strmap() returns a pointer to the new string allocated.
*/

char	*ft_strmap(char const *s, char (*f)(char))
{
	char	*str;
	size_t	i;

	i = -1;
	if (!s || !f)
	{
		ft_error_null("ft_strmap");
		return (NULL);
	}
	if ((str = ft_strnew(ft_strlen(s))))
	{
		while (s[++i])
			str[i] = f(s[i]);
		return (str);
	}
	ft_error_malloc("ft_strmap");
	return (NULL);
}
