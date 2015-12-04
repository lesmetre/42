/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpressen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/01 23:17:46 by mpressen          #+#    #+#             */
/*   Updated: 2015/12/04 23:24:37 by mpressen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char	*s1;
	char	*sub;
	size_t	count;

	s1 = (char *)s;
	count = 0;
	sub = (char *)malloc(sizeof(*sub) * (len + 1));
	if (sub)
	{
		while (count < len)
		{
			sub[count] = s1[start + count];
			count++;
		}
		sub[count] = '\0';
		return (sub);
	}
	return (NULL);
}
