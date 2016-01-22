/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_list.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpressen <mpressen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/21 20:07:53 by mpressen          #+#    #+#             */
/*   Updated: 2016/01/22 19:08:48 by mpressen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	free_list(t_chain **add_list)
{
	t_chain		*tmp;
	
	while (*add_list)
	{
		tmp = (*add_list)->next;
		free_tab((*add_list)->tetrimino);
		free(*add_list);
		*add_list = NULL;
		*add_list = tmp;
	}
	add_list = NULL;
}
