/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_link.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpressen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/09 08:01:25 by mpressen          #+#    #+#             */
/*   Updated: 2015/12/09 08:09:19 by mpressen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "list.h"
#include <stdlib.h>

t_list	*add_link(t_list *list, char *str)
{
	t_list	*tmp;

	tmp = (t_list *)malloc(sizeof(*tmp));
	if (tmp)
	{
		tmp->str = str;
		tmp->next = list;
	}
	return (tmp);
}
