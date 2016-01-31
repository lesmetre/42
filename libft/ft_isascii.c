/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isascii.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpressen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/15 19:10:06 by mpressen          #+#    #+#             */
/*   Updated: 2016/01/30 08:00:27 by mpressen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** The ft_isascii() function tests for an ASCII character,
** which is any character between 0 and octal 0177 inclusive.
*/

int		ft_isascii(int c)
{
	return (c >= 0 && c < 128);
}
