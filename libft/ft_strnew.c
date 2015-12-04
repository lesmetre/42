/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strnew.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpressen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/01 22:35:23 by mpressen          #+#    #+#             */
/*   Updated: 2015/12/04 23:27:47 by mpressen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strnew(size_t size)
{
	char	*str;
	int		size1;

	size1 = size;
	str = (char *)malloc(sizeof(*str) * size);
	if (str)
	{
		while (size1 >= 0)
		{
			str[size1] = '\0';
			size1--;
		}
		return (str);
	}
	return (NULL);
}
