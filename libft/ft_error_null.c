/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error_null.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpressen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/11 06:04:15 by mpressen          #+#    #+#             */
/*   Updated: 2016/01/25 20:28:42 by mpressen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** The ft_error_null() function displays on the standart error input
** an error message about a null parameter given to the function displayed.
*/

void	*ft_error_null(char const *str)
{
	ft_putstr("\033[31merror : ");
	ft_putstr(str);
	ft_putendl(" : null parameter\033[0m");
	return (NULL);
}
