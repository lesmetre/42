/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpressen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/26 21:50:47 by mpressen          #+#    #+#             */
/*   Updated: 2015/11/26 22:16:08 by mpressen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>

int		ft_atoi(char *str)
{
	int count;
	int number;

	count = 0;
	number = 0;

	if (str[0] == '+' || str[0] == '-')
		count++;
	if (str[count] < '0' || str[count] > '9')
		return (0);
	while (str[count] >= '0' && str[count] <= '9')
	{
		number = str[count] - '0'+ number * 10;
		count++;
	}
	if (str[0] == '-')
		number = -number;
	return (number);
}

int		main(void)
{
	printf("%d\n", atoi("-2147483648"));
	printf("%d\n", ft_atoi("-2147483648"));
	return (0);
}
