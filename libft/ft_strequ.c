/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strequ.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpressen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/27 21:51:53 by mpressen          #+#    #+#             */
/*   Updated: 2016/02/02 22:29:18 by mpressen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** The function ft_strequ() lexicographically compares s1 and s2.
** If equals, the function returns 1. If not, 0.
*/

int		ft_strequ(char const *s1, char const *s2)
{
	if (!(s1) || !(s2))
	{
		ft_error_null("ft_strequ");
		return (0);
	}
	if (ft_strcmp(s1, s2) == 0)
		return (1);
	return (0);
}
