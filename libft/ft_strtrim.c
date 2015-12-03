/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpressen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/01 23:52:02 by mpressen          #+#    #+#             */
/*   Updated: 2015/12/02 00:24:26 by mpressen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

size_t		ft_strlentrim(char const *s)
{
	size_t	len;
	size_t	begin;

	begin = 1;
	len = 0;
	while (*s)
	{
		if ((*s == ' ' || *s == '\n' || *s == '\t') && begin == 1)
			s++;
		else
		{
			begin = 0;
			len++;
			s++;
		}
	}
	while (*--s == ' ' || *s == '\n' || *s == '\t')
	{
		len--;
	}
	return (len);
}

char		*ft_strtrim(char const *s)
{
	char	*trim;
	size_t	len;
	size_t	begin;

	begin = 1;
	len = ft_strlentrim(s);
	trim = (char *)malloc(sizeof(*trim) * (len + 1));
	if (trim)
	{
		while (len > 0)
		{
			if ((*s == ' ' || *s == '\n' || *s == '\t') && begin == 1)
				s++;
			else
			{
				begin = 0;
				*trim = *s;
				trim++;
				s++;
			}
		}
		*trim = '\0';
		return (trim);
	}
	return (NULL);
}
