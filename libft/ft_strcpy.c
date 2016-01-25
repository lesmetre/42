/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpressen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/30 23:42:15 by mpressen          #+#    #+#             */
/*   Updated: 2016/01/25 20:09:20 by mpressen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** The strcpy() function copies the string src to dst
** (including the terminating '\0' character).
** The function returns dst.
*/

char	*ft_strcpy(char *dst, const char *src)
{
	size_t count;

	count = 0;
	while (src[count])
	{
		dst[count] = src[count];
		count++;
	}
	dst[count] = '\0';
	return (dst);
}
