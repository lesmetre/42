/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strclr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpressen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/27 22:02:32 by mpressen          #+#    #+#             */
/*   Updated: 2016/01/25 04:54:27 by mpressen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** The ft_strclr() set character's value from a string to 0.
*/

void	ft_strclr(char *s)
{
	size_t count;

	count = 0;
	if (!(s))
		ft_error_null("ft_strclr");
	else
		while (s[count])
		{
			s[count] = '\0';
			count++;
		}
}
