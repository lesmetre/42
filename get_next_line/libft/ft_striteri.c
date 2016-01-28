/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpressen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/05 00:31:49 by mpressen          #+#    #+#             */
/*   Updated: 2016/01/25 21:04:05 by mpressen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** The ft_striteri() applies the fonction f
** to each character of the string, precising his index.
** Each string's character is given to f by his address
** in order to allow modification, if necessary.
*/

void	ft_striteri(char *s, void (*f)(unsigned int, char *))
{
	unsigned int i;

	i = 0;
	if (!(s) || !(f))
		ft_error_null("ft_striteri");
	else
		while (*s)
			f(i++, s++);
}
