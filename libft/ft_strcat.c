/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpressen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/30 23:58:49 by mpressen          #+#    #+#             */
/*   Updated: 2016/01/31 08:20:24 by mpressen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** The ft_strcat() functions appends a copy of the null-terminated string s2
** to the end of the null-terminated string s1, then add a terminating `\0'.
** The string s1 must have sufficient space to hold the result.
** The function returns the pointer s1.
*/

char	*ft_strcat(char *s1, const char *s2)
{
	size_t i;
	size_t j;

	i = ft_strlen(s1);
	j = 0;
	while (s2[j])
		s1[i++] = s2[j++];
	s1[i] = '\0';
	return (s1);
}
