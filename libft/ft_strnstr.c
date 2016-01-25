/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpressen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/01 00:58:00 by mpressen          #+#    #+#             */
/*   Updated: 2016/01/25 20:05:49 by mpressen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** The strnstr() function locates the first occurrence
** of the null-terminated string little in the string big,
** where not more than len characters are searched.
** If little is an empty string, big is returned;
** if little occurs nowhere in big, NULL is returned;
** otherwise a pointer to the first character
** of the first occurrence of little is returned.
*/

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	count1;
	size_t	count2;
	char	*s11;
	char	*s22;

	s11 = (char *)big;
	s22 = (char *)little;
	count1 = 0;
	count2 = 0;
	if (!(*s22))
		return (s11);
	while (s11[count1] && count1 < len)
	{
		if (s11[count1] == s22[count2])
		{
			while (s22[count2] && s11[count1 + count2] == s22[count2]
					&& count1 + count2 < len)
				count2++;
			if (s22[count2] == '\0')
				return (s11 + count1);
		}
		count2 = 0;
		count1++;
	}
	return (NULL);
}
