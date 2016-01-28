/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpressen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/01 22:47:34 by mpressen          #+#    #+#             */
/*   Updated: 2016/01/25 04:51:26 by mpressen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

/*
** The ft_strdel() desallocates a string's memory.
** The strings memory is set to NULL.
*/

void	ft_strdel(char **as)
{
	ft_memdel((void **)as);
}
