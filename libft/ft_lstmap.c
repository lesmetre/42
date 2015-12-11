/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpressen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/10 10:22:00 by mpressen          #+#    #+#             */
/*   Updated: 2015/12/11 02:54:23 by mpressen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f) (t_list *elem))
{
	t_list	*new;
	t_list	*begin;

	if (!lst || !f)
	{
		ft_putendl("\033[31merror : ft_lstmap : null parameter\033[0m");
		return (NULL);
	}
	begin = NULL;
	new = (*f)(lst);
	begin = new;
	while (lst->next)
	{
		new->next = (*f)(lst->next);
		new = new->next;
		lst = lst->next;
	}
	new->next = NULL;
	return (begin);
}
