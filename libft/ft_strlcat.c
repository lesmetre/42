/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpressen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/30 23:58:49 by mpressen          #+#    #+#             */
/*   Updated: 2016/01/25 02:54:46 by mpressen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** The strlcat() function concatenate strings.
** The strlcat() take the full size of the buffer (not just the length)
** and guarantee to NUL-terminate the result
** (as long as there is at least one byte free in dst).
** Note that a byte for the NUL should be included in size.
** The strlcat() function appends the NUL-terminated string src
** to the end of dst. It will append at most size - strlen(dst) - 1 bytes,
** NUL-terminating the result. The strlcat() function return
** the initial length of dst plus the length of src.
** Note however, that if strlcat() traverses size characters
** without finding a NUL,
** the length of the string is considered to be size
** and the destination string will not be NUL-terminated.
*/

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t i;
	size_t j;
	size_t end_dst;

	i = 0;
	j = 0;
	while (dst[i] && i < size)
		i++;
	end_dst = i;
	while (src[j] && i < size - 1)
		dst[i++] = src[j++];
	if (i < size)
		dst[i] = '\0';
	return (end_dst + ft_strlen(src));
}
