/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpressen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/30 23:42:15 by mpressen          #+#    #+#             */
/*   Updated: 2015/12/02 23:55:06 by mpressen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strcpy(char *dst, const char *src, size_t n)
{
	size_t count;

	count = 0;
	while (src[count] && count < n)
	{
		dst[count] = src[count];
		count++;
	}
	while (count < n)
	{
		dst[count] = '\0';
		count++;
	}
	dst[count] = '\0';
	return (dst);
}
