/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpressen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/28 01:29:59 by mpressen          #+#    #+#             */
/*   Updated: 2016/01/30 08:38:53 by mpressen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** The ft_memccpy() function copies bytes from string src to string dst.
** If the character c occurs in the string src, the copy stops
** and a pointer to the byte after the copy of c in the string dst is returned.
** Otherwise, n bytes are copied, and a NULL pointer is returned.
*/

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	unsigned char		*dst1;
	unsigned char		*src1;
	size_t				i;

	i = -1;
	dst1 = (unsigned char*)dst;
	src1 = (unsigned char*)src;
	while (++i < n)
	{
		dst1[i] = src1[i];
		if (src1[i] == (unsigned char)c)
			return (dst + i + 1);
	}
	return (NULL);
}
