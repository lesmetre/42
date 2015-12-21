/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_list.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpressen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/09 08:06:53 by mpressen          #+#    #+#             */
/*   Updated: 2015/12/10 05:36:54 by mpressen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "list.h"
#include <unistd.h>

void	ft_putstr(char *str)
{
	while (*str)
		write(1, str++, 1);
}

void	print_list(t_list *list)
{
	while (list)
	{
		ft_putstr(list->str);
		list = list->next;
	}
}
