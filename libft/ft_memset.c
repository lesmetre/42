/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpressen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/27 22:06:22 by mpressen          #+#    #+#             */
/*   Updated: 2016/01/25 20:05:16 by mpressen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** The memset() function writes len bytes of value c to the string b.
** The function returns its first argument.
*/

void	*ft_memset(void *b, int c, size_t len)
{
	char	*str;

	str = (char *)b;
	while (len > 0)
	{
		str[len - 1] = c;
		len--;
	}
	return (b);
}
