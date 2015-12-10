/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpressen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/10 23:51:09 by mpressen          #+#    #+#             */
/*   Updated: 2015/12/10 23:55:40 by mpressen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstiter(t_list *lst, void (*f) (t_list *elem))
{
	t_list	*begin;

	if (!(lst) || !(f))
		return (NULL);
	begin = lst;
	while (lst)
	{
		f(lst);
		lst = lst->next;
	}
	return (begin);
}
