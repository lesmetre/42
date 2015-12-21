/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpressen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/27 19:59:58 by mpressen          #+#    #+#             */
/*   Updated: 2015/11/27 20:20:08 by mpressen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char *ft_strstr(char *str, char *to_find)
{
	unsigned int i;
	unsigned int z;
	unsigned int to_find_size;

	i = 0;
	z = 0;
	to_find_size = 0;
	while (to_find[to_find_size])
		to_find_size++;
	if (to_find_size == 0)
		return (str);
	while (str[i])
	{
		while (to_find[z] == str[z + i])
		{
			if (z == to_find_size - 1)
				return (str + i);
			z++;
		}
		z = 0;
		i++;
	}
	return (0);
}
