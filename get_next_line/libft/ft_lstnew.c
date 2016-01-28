/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpressen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/10 08:44:49 by mpressen          #+#    #+#             */
/*   Updated: 2016/01/25 07:00:43 by mpressen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

/*
** The function ft_lstnew() allocates and returns a new link to the linked list.
** The content and content_size are initialized by copy of the parameters.
** If content is nul, the content field of the new link is set to NULL
** and content_size is set to 0.
** Next is inizialised to NULL.
** If allocation fails, the function returns NULL.
*/

t_list	*ft_lstnew(void	const *content, size_t content_size)
{
	t_list	*list;

	list = NULL;
	if (!(list = (t_list*)malloc(sizeof(*list))))
		return (NULL);
	if (!(content))
	{
		list->content = NULL;
		list->content_size = 0;
	}
	else
	{
		list->content = ft_memdup(content, content_size);
		list->content_size = content_size;
	}
	list->next = NULL;
	return (list);
}
