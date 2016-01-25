/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpressen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/30 23:42:15 by mpressen          #+#    #+#             */
/*   Updated: 2016/01/25 03:11:29 by mpressen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** The strncpy() function copy at most len characters from src into dst.
** If src is less than len characters long,
** the remainder of dst is filled with `\0' characters.
** Otherwise, dst is not terminated.
** The strncpy() functions return dst.
*/

char	*ft_strncpy(char *dst, const char *src, size_t len)
{
	size_t count;

	count = 0;
	while (src[count] && count < len)
	{
		dst[count] = src[count];
		count++;
	}
	while (count < len)
	{
		dst[count] = '\0';
		count++;
	}
	return (dst);
}
