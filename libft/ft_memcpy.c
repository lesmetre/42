/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpressen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/27 23:08:34 by mpressen          #+#    #+#             */
/*   Updated: 2016/02/02 18:05:38 by mpressen         ###   ########.fr       */
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
	while (n > 0)
	{
		((unsigned char*)dst)[n - 1] = ((unsigned char*)src)[n - 1];
		n--;
	}
	return (dst);
}
