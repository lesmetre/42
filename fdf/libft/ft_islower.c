/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_islower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpressen <mpressen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/25 20:39:59 by mpressen          #+#    #+#             */
/*   Updated: 2016/01/25 20:46:17 by mpressen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** The ft_islower() function tests for any lower-case letter.
** The function returns zero if the character tests false
** and returns non-zero if the character tests true.
*/

int		ft_islower(int c)
{
	return (c >= 'a' && c <= 'z');
}
