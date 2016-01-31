/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpressen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/27 23:08:34 by mpressen          #+#    #+#             */
/*   Updated: 2016/01/30 08:37:58 by mpressen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** The ft_memcpy() function copies n bytes from memory area src
** to memory area dst.
** The function returns the original value of dst.
*/

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned char		*dst1;
	unsigned char		*src2;

	dst1 = (unsigned char*)dst;
	src2 = (unsigned char*)src;
	while (n > 0)
	{
		dst1[n - 1] = src2[n - 1];
		n--;
	}
	return (dst);
}
