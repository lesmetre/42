/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpressen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/01 23:17:46 by mpressen          #+#    #+#             */
/*   Updated: 2015/12/11 03:03:48 by mpressen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char	*s1;
	char	*sub;
	size_t	count;

	count = 0;
	if (!(s))
	{
		ft_putendl("\033[31merror : ft_strsub : null parameter\033[0m");
		return (NULL);
	}
	s1 = (char *)s;
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
	ft_putendl("\033[31merror : ft_strsub : malloc failed\033[0m");
	return (NULL);
}
