/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_push_params.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpressen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/10 06:49:51 by mpressen          #+#    #+#             */
/*   Updated: 2015/12/10 07:13:35 by mpressen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"
#include <string.h>

void	ft_list_push_front(t_list **begin_list, void *data);

t_list	*ft_list_push_params(int ac, char **av)
{
	t_list	*list;
	int		i;

	i = 2;
	list = NULL;
	if (ac == 1)
		return (NULL);
	list = (t_list*)malloc(sizeof(*list));
	if (list)
	{
		list->data = av[1];
		list->next = NULL;
	}
	while (i < ac)
		ft_list_push_front(&list, av[i++]);
	return (list);
}
