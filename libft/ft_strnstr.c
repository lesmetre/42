/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpressen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/01 00:58:00 by mpressen          #+#    #+#             */
/*   Updated: 2015/12/02 23:55:18 by mpressen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *s1, const char *s2, size_t n)
{
	size_t	count1;
	size_t	count2;

	count1 = 0;
	count2 = 0;
	if (!(*s2))
		return ((char *)s1);
	while (s1[count1] && count1 < n)
	{
		if (s1[count1] == s2[count2])
		{
			while (s1[count1 + count2] == s2[count2])
			{
				count2++;
			}
			if (s2[count2] == '\0')
			{
				return ((char *)s1 + count1);
			}
		}
		count2 = 0;
		count1++;
	}
	return (NULL);
}
