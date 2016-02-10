/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tolower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpressen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/01 02:24:17 by mpressen          #+#    #+#             */
/*   Updated: 2016/01/31 10:11:23 by mpressen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** The ft_tolower() function converts an upper-case letter
** to the corresponding lower-case letter, and returns it.
*/

int		ft_tolower(int c)
{
	return (c >= 'A' && c <= 'Z' ? c + 'a' - 'A' : c);
}
