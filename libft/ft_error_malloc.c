/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error_malloc.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpressen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/11 06:04:15 by mpressen          #+#    #+#             */
/*   Updated: 2016/01/25 20:28:45 by mpressen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** The ft_error_malloc() function displays on the standart error input
** an error message about a failed memory allocation, and where it happened.
*/

void	*ft_error_malloc(char const *str)
{
	ft_putstr_fd("\033[31merror : ", 2);
	ft_putstr_fd(str, 2);
	ft_putendl_fd(" : malloc failed\033[0m", 2);
	return (NULL);
}
