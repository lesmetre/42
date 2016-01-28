/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpressen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/27 21:30:03 by mpressen          #+#    #+#             */
/*   Updated: 2016/01/25 06:49:28 by mpressen         ###   ########.fr       */
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
		ft_putendl("\033[31merror : ft_putstr.c : null parameter\033[0m");
	else
	{
		while (*s)
			write(1, s++, 1);
		write(1, "\n", 1);
	}
}
