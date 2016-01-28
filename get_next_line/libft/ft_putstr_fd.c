/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpressen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/27 21:30:03 by mpressen          #+#    #+#             */
/*   Updated: 2016/01/25 20:15:12 by mpressen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <unistd.h>

/*
** The function ft_putstr_fd() displays the string s on the file descriptor fd.
*/

void	ft_putstr_fd(char const *s, int fd)
{
	if (!(s))
		ft_error_null("ft_putstr_fd");
	else
		while (*s)
			write(fd, s++, 1);
}
