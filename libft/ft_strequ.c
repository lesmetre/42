/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strequ.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpressen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/27 21:51:53 by mpressen          #+#    #+#             */
/*   Updated: 2016/01/30 09:26:08 by mpressen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** The function ft_strequ() lexicographically compares s1 and s2.
** If equals, the function returns 1. If not, 0.
*/

int		ft_strequ(char const *s1, char const *s2)
{
	size_t i;

	i = -1;
	if (!(s1) || !(s2))
	{
		ft_error_null("ft_strequ");
		return (0);
	}
	while (s1[++i] && s2[i])
		if (s1[i] != s2[i])
			return (0);
	return (1);
}
