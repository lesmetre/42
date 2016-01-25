/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpressen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/30 23:58:49 by mpressen          #+#    #+#             */
/*   Updated: 2016/01/25 02:48:58 by mpressen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** The strncat() functions append a copy of the null-terminated string s2
** to the end of the null-terminated string s1, then add a terminating `\0'.
** The string s1 must have sufficient space to hold the result.
** The strncat() function appends not more than n characters from s2,
** and then adds a terminating `\0'.
** The strncat() function return the pointer s1.
*/

char	*ft_strncat(char *s1, const char *s2, size_t n)
{
	size_t count1;
	size_t count2;

	count1 = 0;
	count2 = 0;
	while (s1[count1])
		count1++;
	while (s2[count2] && n > 0)
	{
		s1[count1] = s2[count2];
		count1++;
		count2++;
		n--;
	}
	s1[count1] = '\0';
	return (s1);
}
