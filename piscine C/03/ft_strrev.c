/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrev.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpressen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/26 20:49:12 by mpressen          #+#    #+#             */
/*   Updated: 2015/11/26 21:48:15 by mpressen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

char	*ft_strrev(char *str)
{
	int		counter;
	int		size_str;
	char	temp;

	if (str)
	{
		counter = 0;
		size_str = 0;
		while (str[size_str])
			size_str++;
		size_str -= 1;
		while (counter < size_str)
		{
			temp = str[size_str];
			str[size_str] = str[counter];
			str[counter] = temp;
			counter++;
			size_str--;
		}
	}
	return (str);
}

int		main(void)
{
	printf("%s\n", ft_strrev("alome"));
	return (0);
}
