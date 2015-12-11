/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpressen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/10 23:51:09 by mpressen          #+#    #+#             */
/*   Updated: 2015/12/11 03:01:28 by mpressen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstiter(t_list *lst, void (*f) (t_list *elem))
{
	if (!(lst) || !(*f))
		ft_putendl("\033[31merror : ft_lstiter : null parameter\033[0m");
	else
	{
		while (lst)
		{
			f(lst);
			lst = lst->next;
		}
	}
}
