/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpressen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/01 22:26:35 by mpressen          #+#    #+#             */
/*   Updated: 2016/01/25 04:47:31 by mpressen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

/*
** The ft_memdel() deallocates memory
** and set the pointer's memory to NULL.
*/

void	ft_memdel(void **ap)
{
	if (!(ap))
		ft_error_null("ft_memdel");
	else
	{
		free(*ap);
		*ap = NULL;
	}
}
