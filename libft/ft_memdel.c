/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpressen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/01 22:26:35 by mpressen          #+#    #+#             */
/*   Updated: 2015/12/11 02:36:53 by mpressen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

void	ft_memdel(void **ap)
{
	if (!(ap))
		ft_putendl("\033[31merror : ft_memdel : null parameter\033[0m");
	else
	{
		free(*ap);
		*ap = NULL;
	}
}
