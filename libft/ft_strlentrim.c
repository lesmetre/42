/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlentrim.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpressen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/11 01:30:48 by mpressen          #+#    #+#             */
/*   Updated: 2016/01/25 21:07:50 by mpressen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** The ft_strlentrim() function computes the length of the string s,
** without counting the white spaces.
** The function returns the number of characters found
** before the terminating NUL character.
*/

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
		while (ft_isspace((int)s[i]) && begin == 1)
			i++;
		begin = 0;
		len++;
		i++;
	}
	i--;
	while (ft_isspace((int)s[i]))
	{
		len--;
		i--;
	}
	return (len);
}
