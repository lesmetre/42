/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpressen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/27 21:30:03 by mpressen          #+#    #+#             */
/*   Updated: 2016/01/30 08:55:29 by mpressen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <unistd.h>

/*
** The function ft_putendl() displays the string s on the standart output,
** followed by a '\n'.
*/

void	ft_putendl(char const *s)
{
	if (!(s))
		ft_error_null("ft_putendl");
	else
	{
		write(1, s, ft_strlen(s));
		write(1, "\n", 1);
	}
}
