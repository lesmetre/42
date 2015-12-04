/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpressen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/01 03:27:06 by mpressen          #+#    #+#             */
/*   Updated: 2015/12/04 22:59:06 by mpressen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_atoi(const char *str)
{
	size_t	count;
	int		res;
	int		sign;
	char	*str1;

	str1 = (char *)str;
	count = 0;
	res = 0;
	sign = 1;
	while (str1[count] == '\n' || str1[count] == '\f' || str1[count] == '\r'
		|| str1[count] == "\v" || str1[count] == " " || str1[count] == "\t")
		count++;
	if (str1[count] == '-' || str1[count] == '+')
	{
		if (str1[count] == '-')
			sign = -1;
		count++;
	}
	while (str1[count] >= '0' && str1[count] <= '9')
	{
		res = res * 10 + str1[count] - '0';
		count++;
	}
	return (res * sign);
}
