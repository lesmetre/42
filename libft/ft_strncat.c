/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpressen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/30 23:58:49 by mpressen          #+#    #+#             */
/*   Updated: 2016/01/31 08:19:39 by mpressen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** The ft_strncat() functions appends a copy of the null-terminated string s2
** to the end of the null-terminated string s1, then add a terminating `\0'.
** The string s1 must have sufficient space to hold the result.
** The function appends not more than n characters from s2,
** and then adds a terminating `\0'.
** The function returns the pointer s1.
*/

char	*ft_strncat(char *s1, const char *s2, size_t n)
{
	size_t i;
	size_t j;

	i = ft_strlen(s1);
	j = 0;
	while (s2[j] && n-- > 0)
		s1[i++] = s2[j++];
	s1[i] = '\0';
	return (s1);
}
