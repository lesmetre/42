/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpressen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/01 21:40:14 by mpressen          #+#    #+#             */
/*   Updated: 2016/01/25 04:39:41 by mpressen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

/*
** The ft_memalloc() allocates memory.
** The allocated memory is filled with bytes of value zero.
** If the allocation fails, the fonction returns NULL.
** If not, ft_memalloc() returns a pointer to the allocated memory.
*/

void	*ft_memalloc(size_t size)
{
	void	*mem;

	mem = (void *)malloc(size);
	if (mem)
	{
		ft_bzero(mem, size);
		return (mem);
	}
	return (ft_error_malloc("ft_memalloc"));
}
