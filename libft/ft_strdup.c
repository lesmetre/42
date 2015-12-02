/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpressen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/30 21:35:09 by mpressen          #+#    #+#             */
/*   Updated: 2015/12/02 23:53:25 by mpressen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strdup(const char *s1)
{
	char	*s2;
	size_t	count;

	count = 0;
	while (s1[count])
		count++;
	s2 = (char *)malloc(sizeof(*s1) * count);
	if (s2)
	{
		while (count > 0)
		{
			s2[count - 1] = s1[count - 1];
			count--;
		}
		return (s2);
	}
	return (NULL);
}
