/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpressen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/11 00:51:50 by mpressen          #+#    #+#             */
/*   Updated: 2016/01/25 07:10:45 by mpressen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

/*
** The function ft_lstdel() desallocates links of a linked list,
** starting with the link alst.
** Finally, the pointer to alst is set to NULL.
*/

void	ft_lstdel(t_list **alst, void (*del) (void*, size_t))
{
	t_list	*tmp;

	while (*alst)
	{
		tmp = (*alst)->next;
		del((*alst)->content, (*alst)->content_size);
		ft_memdel((void **)alst);
		*alst = tmp;
	}
	free(tmp);
}
