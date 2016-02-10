/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpressen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/10 23:51:09 by mpressen          #+#    #+#             */
/*   Updated: 2016/01/30 08:12:51 by mpressen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** The function ft_lstiter() applies the function f
** to each link of the linked list lst.
*/

void	ft_lstiter(t_list *lst, void (*f) (t_list *elem))
{
	if (!(lst) || !(f))
		ft_error_null("ft_lstiter");
	else
		while (lst)
		{
			f(lst);
			lst = lst->next;
		}
}
