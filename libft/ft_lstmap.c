/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpressen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/10 10:22:00 by mpressen          #+#    #+#             */
/*   Updated: 2016/01/25 07:17:50 by mpressen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** The function ft_lstmap allocates and returns a new linked list,
** result of the successives applies of the function f
** on each link of the linked list lst.
** If an allocation fails, ft_lstmap() returns NULL.
*/

t_list	*ft_lstmap(t_list *lst, t_list *(*f) (t_list *elem))
{
	t_list	*new;
	t_list	*begin;

	if (!lst || !f)
		return (ft_error_null("ft_lstmap"));
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
