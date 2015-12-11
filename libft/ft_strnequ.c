/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnequ.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpressen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/27 21:51:53 by mpressen          #+#    #+#             */
/*   Updated: 2015/12/11 03:03:24 by mpressen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strnequ(char const *s1, char const *s2, size_t n)
{
	size_t count;

	count = 0;
	if (!(s1) || !(s2))
	{
		ft_putendl("\033[31merror : ft_strnequ : null parameter\033[0m");
		return (0);
	}
	while ((s1[count] || s2[count]) && count < n)
	{
		if (s1[count] != s2[count])
			return (0);
		count++;
	}
	return (1);
}
