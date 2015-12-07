/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpressen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/01 01:38:39 by mpressen          #+#    #+#             */
/*   Updated: 2015/12/07 05:47:38 by mpressen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t			s1len;
	size_t			s2len;
	unsigned char	*s11;
	unsigned char	*s22;

	if (!(s1) || !(s2) || !(n))
		return (0);
	s11 = (unsigned char *)s1;
	s22 = (unsigned char *)s2;
	s1len = ft_strlen(s1);
	s2len = ft_strlen(s2);
	if (s1len < n && s2len < n)
	{
		if (s1len > s2len)
			n = s1len;
		else
			n = s2len;
	}
	return (memcmp(s11, s22, n));
}
