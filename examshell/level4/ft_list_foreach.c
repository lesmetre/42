/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_foreach.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: exam <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/15 12:12:54 by exam              #+#    #+#             */
/*   Updated: 2015/12/15 12:18:50 by exam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

void	ft_list_foreach(t_list *begin_list, void (*f)(void*))
{
	if (begin_list && f)
	{
		while (begin_list)
		{
			f(begin_list->data);
			begin_list = begin_list->next;
		}
	}
}
