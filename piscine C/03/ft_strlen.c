/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpressen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/26 20:28:24 by mpressen          #+#    #+#             */
/*   Updated: 2015/11/26 20:32:13 by mpressen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int		ft_strlen(char *str)
{
	int count;

	count = 0;
	while (*str)
	{
		count++;
		str++;
	}
	return (count);
}

int		main(void)
{
	printf("%d\n", ft_strlen("yolo"));
	return (0);
}
