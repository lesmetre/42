/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpressen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/01 02:24:17 by mpressen          #+#    #+#             */
/*   Updated: 2016/01/25 02:59:17 by mpressen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** The toupper() function converts a lower-case letter
** to the corresponding upper-case letter.
** If the argument is a lower-case letter, the toupper() function returns
** the corresponding upper-case letter if there is one;
** otherwise, the argument is returned unchanged.
*/

int		ft_toupper(int c)
{
	if (c >= 'a' && c <= 'z')
		c = c + 'A' - 'a';
	return (c);
}
