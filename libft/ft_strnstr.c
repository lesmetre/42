/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpressen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/01 00:58:00 by mpressen          #+#    #+#             */
/*   Updated: 2016/01/31 08:43:27 by mpressen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** The ft_strnstr() function locates the first occurrence
** of the null-terminated string little in the string big,
** where not more than len characters are searched.
** If little is an empty string, big is returned;
** if little occurs nowhere in big, NULL is returned;
** otherwise a pointer to the first character
** of the first occurrence of little is returned.
*/

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	j;

	i = -1;
	j = 0;
	if (!(*little))
		return ((char*)big);
	while (big[++i] && i < len)
	{
		if (big[i] == little[j])
		{
			while (little[j] && big[i + j] == little[j]
					&& i + j < len)
				j++;
			if (!little[j])
				return ((char*)big + i);
		}
		j = 0;
	}
	return (NULL);
}
