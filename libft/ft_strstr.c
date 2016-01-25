/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpressen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/01 00:58:00 by mpressen          #+#    #+#             */
/*   Updated: 2016/01/25 00:16:33 by mpressen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** The strstr() function locates the first occurrence
** of the null-terminated string little in the null-terminated string big.
** If little is an empty string, big is returned;
** if little occurs nowhere in big, NULL is returned;
** otherwise a pointer to the first character
** of the first occurrence of little is returned.
*/

char	*ft_strstr(const char *big, const char *little)
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
	while (s11[count1])
	{
		if (s11[count1] == s22[count2])
		{
			while (s22[count2] && s11[count1 + count2] == s22[count2])
				count2++;
			if (s22[count2] == '\0')
				return (s11 + count1);
		}
		count2 = 0;
		count1++;
	}
	return (NULL);
}
