/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error_null.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpressen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/11 06:04:15 by mpressen          #+#    #+#             */
/*   Updated: 2016/01/31 10:28:38 by mpressen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** The ft_error_null() function displays on the standart error output
** an error message about a null parameter given to the function displayed.
*/

void	ft_error_null(char const *str)
{
	ft_putstr_fd("\033[31merror : ", 2);
	ft_putstr_fd(str, 2);
	ft_putendl_fd(" : null parameter\033[0m", 2);
}
