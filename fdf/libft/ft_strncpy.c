/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpressen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/30 23:42:15 by mpressen          #+#    #+#             */
/*   Updated: 2016/01/31 08:27:40 by mpressen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** The ft_strncpy() function copies at most len characters from src into dst.
** If src is less than len characters long,
** the remainder of dst is filled with `\0' characters.
** Otherwise, dst is not terminated.
** The function return dst.
*/

char	*ft_strncpy(char *dst, const char *src, size_t len)
{
	size_t i;

	i = -1;
	while (src[++i] && i < len)
		dst[i] = src[i];
	i--;
	while (++i < len)
		dst[i] = '\0';
	return (dst);
}
