/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isspace_full.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpressen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/11 01:00:39 by mpressen          #+#    #+#             */
/*   Updated: 2015/12/11 01:06:44 by mpressen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_isspace_full(int c)
{
	if (str[count] == '\n' || str[count] == '\f' || str[count] == '\r'
            || str[count] == '\v' || str[count] == ' ' || str[count] == '\t')
		return (1);
	return (0);
}
