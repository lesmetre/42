/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpressen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/01 23:52:02 by mpressen          #+#    #+#             */
/*   Updated: 2015/12/11 03:42:05 by mpressen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

static char	*ft_strtrim2(char const *s, size_t i, size_t j, size_t begin)
{
	char	*trim;
	size_t	len;

	if (!(s))
	{
		ft_putendl("\033[31merror : ft_strtrim : null parameter\033[0m");
		return (NULL);
	}
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
	ft_putendl("\033[31merror : ft_strtrim : malloc failed\033[0m");
	return (NULL);
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
