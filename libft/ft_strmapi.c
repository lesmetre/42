/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpressen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/05 00:49:41 by mpressen          #+#    #+#             */
/*   Updated: 2016/01/31 08:15:40 by mpressen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

/*
** The ft_strmapi() applies the function f
** to each character of the string, precising his index
** in order to allocate a new string, result of f's successives applies.
** The ft_strmap() returns a pointer to the new string allocated.
*/

char	*ft_strmapi(char const *s, char (*f) (unsigned int, char))
{
	char			*str;
	unsigned int	i;

	i = -1;
	if (!s || !f)
	{
		ft_error_null("ft_strmapi");
		return (NULL);
	}
	if ((str = ft_strnew(ft_strlen(s))))
	{
		while (s[++i])
			str[i] = f(i, s[i]);
		return (str);
	}
	ft_error_malloc("ft_strmapi");
	return (NULL);
}
