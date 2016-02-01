/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpressen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/01 03:27:06 by mpressen          #+#    #+#             */
/*   Updated: 2016/02/01 21:54:22 by mpressen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** The ft_atoi() function converts the initial portion
** of the string pointed to by str to int representation.
*/

int		ft_atoi(const char *str)
{
	size_t	i;
	int		res;
	int		sign;

	i = 0;
	res = 0;
	sign = 1;
	while (ft_isspace_full((int)str[i]))
		i++;
	if (str[i] == '-' || str[i] == '+')
		if (str[i++] == '-')
			sign = -1;
	while (ft_isdigit((int)str[i]))
		res = res * 10 + str[i++] - '0';
	return (res * sign);
}
