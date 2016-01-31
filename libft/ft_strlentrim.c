/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlentrim.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpressen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/11 01:30:48 by mpressen          #+#    #+#             */
/*   Updated: 2016/01/31 08:04:06 by mpressen         ###   ########.fr       */
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
	size_t i;
	size_t j;

	i = 0;
	j = 0;
	while (ft_isspace((int)s[i]))
		i++;
	i--;
	while (s[++i])
		j++;
	if (j)
		while (ft_isspace((int)s[--i]))
			j--;
	return (j);
}
