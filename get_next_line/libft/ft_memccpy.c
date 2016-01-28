/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpressen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/28 01:29:59 by mpressen          #+#    #+#             */
/*   Updated: 2016/01/25 07:46:47 by mpressen         ###   ########.fr       */
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
	char		*dst1;
	const char	*src1;
	size_t		count;

	count = 0;
	dst1 = dst;
	src1 = src;
	while (count < n)
	{
		dst1[count] = src1[count];
		if (src1[count] == c)
			return (dst + count + 1);
		count++;
	}
	return (NULL);
}
