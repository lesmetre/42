/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isspace.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpressen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/11 01:07:19 by mpressen          #+#    #+#             */
/*   Updated: 2016/01/30 07:59:26 by mpressen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** The ft_isspace() function tests for the white-space characters,
** including '\n', '\t' and ' '.
** The function returns zero if the character tests false and returns
** non-zero if the character tests true.
*/

int		ft_isspace(int c)
{
	return (c == '\n' || c == ' ' || c == '\t');
}
