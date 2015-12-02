/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpressen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/27 23:08:34 by mpressen          #+#    #+#             */
/*   Updated: 2015/12/02 23:50:25 by mpressen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	char		*str1;
	const char	*str2;

	str1 = dst;
	str2 = src;
	while (n > 0)
	{
		str1[n - 1] = str2[n - 1];
		n--;
	}
	return (dst);
}
