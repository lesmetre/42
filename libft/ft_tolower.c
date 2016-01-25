/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tolower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpressen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/01 02:24:17 by mpressen          #+#    #+#             */
/*   Updated: 2016/01/25 02:51:32 by mpressen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** The tolower() function converts an upper-case letter
** to the corresponding lower-case letter.
** If the argument is an upper-case letter, the tolower() function returns
** the corresponding lower-case letter if there is one;
** otherwise, the argument is returned unchanged.
*/

int		ft_tolower(int c)
{
	if (c >= 'A' && c <= 'Z')
		c = c + 'a' - 'A';
	return (c);
}
