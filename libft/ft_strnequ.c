/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnequ.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpressen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/27 21:51:53 by mpressen          #+#    #+#             */
/*   Updated: 2016/01/31 08:30:35 by mpressen         ###   ########.fr       */
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
	size_t i;

	i = -1;
	if (!s1 || !s2)
	{
		ft_error_null("ft_strnequ");
		return (0);
	}
	while ((s1[++i] || s2[i]) && i < n)
		if (s1[i] != s2[i])
			return (0);
	return (1);
}
