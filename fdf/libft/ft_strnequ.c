/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnequ.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpressen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/27 21:51:53 by mpressen          #+#    #+#             */
/*   Updated: 2016/02/02 22:31:28 by mpressen         ###   ########.fr       */
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
	if (!s1 || !s2)
	{
		ft_error_null("ft_strnequ");
		return (0);
	}
	if (ft_strncmp(s1, s2, n) == 0)
		return (1);
	return (0);
}
