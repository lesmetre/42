/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlentrim.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpressen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/11 01:30:48 by mpressen          #+#    #+#             */
/*   Updated: 2015/12/11 01:34:12 by mpressen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t		ft_strlentrim(char const *s)
{
	size_t	len;
	size_t	i;
	size_t	begin;

	begin = 1;
	i = 0;
	len = 0;
	while (s[i])
	{
		while (!(ft_isspace(s[i])) && begin == 1)
			i++;
		begin = 0;
		len++;
		i++;
	}
	i--;
	while (s[i] == ' ' || s[i] == '\n' || s[i] == '\t')
	{
		len--;
		i--;
	}
	return (len);
}
