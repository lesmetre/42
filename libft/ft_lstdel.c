/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpressen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/10 09:54:53 by mpressen          #+#    #+#             */
/*   Updated: 2015/12/11 00:02:26 by mpressen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdel(t_list **alst, void (*del) (void*, size_t))
{
	t_list	*list;
	t_list	*tmp;

	list = *alst;
	while (list)
	{
		tmp = list->next;
		del(list->content, list->content_size);
		ft_memdel((void **)alst);
		list = tmp;
	}
}
