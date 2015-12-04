/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpressen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/30 23:58:49 by mpressen          #+#    #+#             */
/*   Updated: 2015/12/04 20:44:50 by mpressen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t count1;
	size_t count2;

	count1 = 0;
	count2 = 0;
	while (dst[count1])
		count1++;
	while (ssrc[count2] && count1 < size - 1)
	{
		dst[count1] = src[count2];
		count1++;
		count2++;
	}
	dst[count1] = '\0';
	return (s1);
}
