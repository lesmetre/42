/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpressen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/01 23:38:30 by mpressen          #+#    #+#             */
/*   Updated: 2015/12/01 23:47:56 by mpressen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*str;
	size_t	count1;
	size_t	count2;

	count1 = 0;
	count2 = 0;
	str = (char *)malloc(sizeof(*str) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (str)
	{
		while (s1[count1])
		{
			str[count1] = s1[count1];
			count1++;
		}
		while (s2[count2])
		{
			str[count1] = s2[count2];
			count1++;
			count2++;
		}
		str[count1] = '\0';
		return (str);
	}
	return (NULL);
}
