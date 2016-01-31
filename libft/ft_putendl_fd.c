/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpressen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/27 21:30:03 by mpressen          #+#    #+#             */
/*   Updated: 2016/01/30 08:56:16 by mpressen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <unistd.h>

/*
** The function ft_putendl_fd() displays the string s
** on the file descriptor fd, followed by a '\n'.
*/

void	ft_putendl_fd(char const *s, int fd)
{
	if (!(s))
		ft_error_null("ft_putendl_fd");
	else
	{
		write(fd, s, ft_strlen(s));
		write(fd, "\n", 1);
	}
}
