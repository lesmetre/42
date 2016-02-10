/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpressen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/28 02:14:05 by mpressen          #+#    #+#             */
/*   Updated: 2016/01/25 20:59:47 by mpressen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

/*
** The ft_memmove() function copies len bytes from string src to string dst.
** The two strings may overlap;
** the copy is always done in a non-destructive manner.
** The function returns the original value of dst.
*/

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char	*dst1;
	unsigned char	*src1;
	size_t			i;

	dst1 = (unsigned char*)dst;
	src1 = (unsigned char*)src;
	i = 0;
	if (src1 < dst1)
	{
		while (++i <= len)
			dst1[len - i] = src1[len - i];
	}
	else
		while (i < len)
		{
			dst1[i] = src1[i];
			i++;
		}
	return (dst);
}
