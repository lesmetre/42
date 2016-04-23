/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpressen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/01 01:59:43 by mpressen          #+#    #+#             */
/*   Updated: 2016/01/30 07:47:29 by mpressen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** The ft_isalnum() function tests for any character
** for which ft_isalpha or ft_isdigit is true.
** The function returns zero if the character tests false
** and returns non-zero if the character tests true.
*/

int		ft_isalnum(int c)
{
	return (ft_isupper(c) || ft_islower(c) || ft_isdigit(c));
}
