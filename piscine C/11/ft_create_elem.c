/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_create_elem.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpressen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/10 05:57:08 by mpressen          #+#    #+#             */
/*   Updated: 2015/12/10 06:25:31 by mpressen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

t_list	*ft_create_elem(void *data)
{
	t_list	*elem;

	elem = NULL;
	elem = (t_list*)malloc(sizeof(*elem));
	if (elem)
	{
		elem->data = data;
		elem->next = NULL;
	}
	return (elem);
}
