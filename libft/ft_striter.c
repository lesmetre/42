/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpressen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/05 00:16:26 by mpressen          #+#    #+#             */
/*   Updated: 2016/01/25 05:19:41 by mpressen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** The ft_striter() apply the fonction f to each character of the string.
** Each character is given by his address to f
** in order to allow modification is necessary.
*/

void	ft_striter(char *s, void (*f)(char *))
{
	if (!(s) || !(f))
		ft_error_null("ft_striter");
	else
		while (*s)
			f((s++));
}
