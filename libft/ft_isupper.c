/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpressen <mpressen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/25 20:28:57 by mpressen          #+#    #+#             */
/*   Updated: 2016/01/25 20:41:07 by mpressen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** The ft_isupper() function tests for any upper-case letter.
** The function returns zero if the character tests false
** and returns non-zero if the character tests true.
*/

int		ft_isupper(int c)
{
	return (c >= 'A' && c <= 'Z');
}
