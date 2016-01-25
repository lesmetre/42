/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpressen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/10 08:44:49 by mpressen          #+#    #+#             */
/*   Updated: 2016/01/25 20:59:33 by mpressen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

/*
** The ft_memdup() function allocates sufficient memory for a copy of the
** memory src, does the copy, and returns a pointer to it.
** If insufficient memory is available,
** NULL is returned and errno is set to ENOMEM.
*/

void	*ft_memdup(const void *src, size_t n)
{
	void	*ret;

	ret = NULL;
	if (!(ret = (void *)malloc(sizeof(*src) * n)))
		return (NULL);
	ft_memcpy(ret, src, n);
	return (ret);
}
