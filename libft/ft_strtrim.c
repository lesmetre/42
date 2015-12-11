/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpressen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/01 23:52:02 by mpressen          #+#    #+#             */
/*   Updated: 2015/12/11 01:51:32 by mpressen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

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
			while (ft_isspace((int)s[i]) && begin == 1)
				i++;
			begin = 0;
			trim[j++] = s[i++];
		}
		trim[j] = '\0';
		return (trim);
	}
	return (NULL);
}
