/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpressen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/01 00:58:00 by mpressen          #+#    #+#             */
/*   Updated: 2016/01/31 09:34:03 by mpressen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** The ft_strstr() function locates the first occurrence
** of the null-terminated string little in the null-terminated string big.
** If little is an empty string, big is returned;
** if little occurs nowhere in big, NULL is returned;
** otherwise a pointer to the first character
** of the first occurrence of little is returned.
*/

char	*ft_strstr(const char *big, const char *little)
{
	size_t	i;
	size_t	j;

	i = -1;
	j = 0;
	if (!(*little))
		return ((char*)big);
	while (big[++i])
	{
		if (big[i] == little[j])
		{
			while (little[j] && big[i + j] == little[j])
				j++;
			if (!little[j])
				return ((char*)big + i);
		}
		j = 0;
	}
	return (NULL);
}
