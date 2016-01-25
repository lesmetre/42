/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpressen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/27 23:08:34 by mpressen          #+#    #+#             */
/*   Updated: 2016/01/25 02:38:35 by mpressen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** The memcpy() function copies n bytes from memory area src to memory area dst.
** The memcpy() function returns the original value of dst.
*/

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned char		*str1;
	unsigned char		*str2;

	str1 = (unsigned char*)dst;
	str2 = (unsigned char*)src;
	while (n > 0)
	{
		str1[n - 1] = str2[n - 1];
		n--;
	}
	return (dst);
}
