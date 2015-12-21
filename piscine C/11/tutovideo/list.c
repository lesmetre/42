/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpressen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/09 07:56:26 by mpressen          #+#    #+#             */
/*   Updated: 2015/12/10 05:45:43 by mpressen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "list.h"
#include <string.h>

int		main(void)
{
	t_list	*list;

	list = NULL;
	list = add_link(list, "toto\n");
	list = add_link(list, "tata\n");
	list = add_link(list, "tutu\n");
	print_list(list);
	return (0);
}
