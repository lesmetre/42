/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_countbits.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpressen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/11 00:58:50 by mpressen          #+#    #+#             */
/*   Updated: 2016/01/30 07:38:31 by mpressen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** The function ft_countbits() returns the number of portions
** splitted by the character c, in the string s.
*/

size_t	ft_countbits(const char *s, char c)
{
	size_t	is_bit;
	size_t	bits;
	size_t	i;

	i = 0;
	is_bit = 0;
	bits = 0;
	while (s[i])
	{
		if (s[i] == c && is_bit)
			is_bit = 0;
		if (s[i] != c && !is_bit)
		{
			bits++;
			is_bit = 1;
		}
		while (s[i] && s[i] == c && !is_bit)
			i++;
		while (s[i] && s[i] != c && is_bit)
			i++;
	}
	return (bits);
}
