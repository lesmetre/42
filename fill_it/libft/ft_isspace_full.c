/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isspace_full.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpressen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/11 01:00:39 by mpressen          #+#    #+#             */
/*   Updated: 2015/12/11 02:05:12 by mpressen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_isspace_full(int c)
{
	if (c == '\n' || c == '\f' || c == '\r'
			|| c == '\v' || c == ' ' || c == '\t')
		return (1);
	return (0);
}
