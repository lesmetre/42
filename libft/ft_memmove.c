/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memmove.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpressen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/28 02:14:05 by mpressen          #+#    #+#             */
/*   Updated: 2015/12/02 23:51:21 by mpressen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	char		*dst1;
	const char	*src1;

	dst1 = dst;
	src1 = src;
	while (len > 0)
	{
		dst1[len - 1] = src1[len - 1];
		len--;
	}
	return (dst);
}
