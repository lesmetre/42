/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpressen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/01 02:24:17 by mpressen          #+#    #+#             */
/*   Updated: 2016/01/31 10:12:10 by mpressen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** The ft_toupper() function converts a lower-case letter
** to the corresponding upper-case letter, and returns it.
*/

int		ft_toupper(int c)
{
	return (c >= 'a' && c <= 'z' ? c + 'A' - 'a' : c);
}
