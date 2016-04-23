/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isspace_full.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpressen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/11 01:00:39 by mpressen          #+#    #+#             */
/*   Updated: 2016/01/30 07:59:13 by mpressen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** The ft_isspace_full() function tests for the white-space characters,
** including '\n', '\t', '\v', '\r', '\f' and ' '.
** The function returns zero if the character tests false and returns
** non-zero if the character tests true.
*/

int		ft_isspace_full(int c)
{
	return (c == '\n' || c == '\f' || c == '\r'
			|| c == '\v' || c == ' ' || c == '\t');
}
