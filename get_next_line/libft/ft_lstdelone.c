/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpressen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/10 09:54:53 by mpressen          #+#    #+#             */
/*   Updated: 2016/01/25 07:08:42 by mpressen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** The function ft_lstdelone() desallocates the link alst of a linked list.
** Field's memory of next must not be freed.
** Finally, the pointer to alst is set to NULL.
*/

void	ft_lstdelone(t_list **alst, void (*del) (void*, size_t))
{
	del((*alst)->content, (*alst)->content_size);
	ft_memdel((void **)alst);
}
