/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnequ.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpressen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/27 21:51:53 by mpressen          #+#    #+#             */
/*   Updated: 2016/01/25 05:42:17 by mpressen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** The function ft_strnequ() lexicographically compares s1 and s2,
** until n characters maximum of if a '\0' is met.
** If equals, the function returns 1. If not, 0.
*/

int		ft_strnequ(char const *s1, char const *s2, size_t n)
{
	size_t count;

	count = 0;
	if (!(s1) || !(s2))
		return ((int)ft_error_null("ft_strnequ"));
	while ((s1[count] || s2[count]) && count < n)
	{
		if (s1[count] != s2[count])
			return (0);
		count++;
	}
	return (1);
}
