/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpressen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/01 23:52:02 by mpressen          #+#    #+#             */
/*   Updated: 2015/12/07 02:32:19 by mpressen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

size_t		ft_strlentrim(char const *s)
{
	size_t	len;
	size_t	i;
	size_t	begin;

	begin = 1;
	i = 0;
	len = 0;
	while (s[i])
	{
		while ((s[i] == ' ' || s[i] == '\n' || s[i] == '\t') && begin == 1)
			i++;
		begin = 0;
		len++;
		i++;
	}
	i--;
	while (s[i] == ' ' || s[i] == '\n' || s[i] == '\t')
	{
		len--;
		i--;
	}
	return (len);
}

char		*ft_strtrim(char const *s)
{
	char	*trim;
	size_t	len;
	size_t	i;
	size_t	j;
	size_t	begin;

	begin = 1;
	i = 0;
	j = 0;
	len = ft_strlentrim(s);
	trim = (char *)malloc(sizeof(*trim) * (len + 1));
	if (trim)
	{
		while (j < len)
		{
			while ((s[i] == ' ' || s[i] == '\n' || s[i] == '\t') && begin == 1)
				i++;
			begin = 0;
			trim[j++] = s[i++];
		}
		trim[j] = '\0';
		return (trim);
	}
	return (NULL);
}
