/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_hexa.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpressen <mpressen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/21 19:27:16 by mpressen          #+#    #+#             */
/*   Updated: 2016/04/21 19:50:53 by mpressen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		ft_atoi_hexa(const char *str)
{
	size_t	i;
	int		res;

	i = 1;
	res = 0;
	while (str[++i])
	{
		if (ft_isdigit(str[i]))
			res = res * 16 + str[i] - '0';
		else
			res = res * 16 + str[i] - 'a' + 10;
	}
	return (res);
}
