/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpressen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/30 21:35:09 by mpressen          #+#    #+#             */
/*   Updated: 2016/02/01 21:46:02 by mpressen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

/*
** The ft_strdup() function allocates sufficient memory for a copy of the
** string s1, does the copy, and returns a pointer to it.
** If insufficient memory is available,
** NULL is returned and errno is set to ENOMEM.
*/

char	*ft_strdup(const char *s1)
{
	char	*dup;
	int		i;

	i = -1;
	if ((dup = ft_strnew(ft_strlen(s1))))
	{
		while (s1[++i])
			dup[i] = (char)s1[i];
		return (dup);
	}
	return (NULL);
}
