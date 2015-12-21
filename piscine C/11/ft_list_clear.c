/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_clear.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpressen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/10 07:15:53 by mpressen          #+#    #+#             */
/*   Updated: 2015/12/10 07:30:12 by mpressen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"
#include <stdlib.h>

void	ft_list_clear(t_list **begin_list)
{
	t_list	list;
	t_list	tmp;

	list = *begin_list;
	tmp = NULL;
	while (list)
	{
		tmp = list->next;
		free(list);
		list = tmp;
	}
}
