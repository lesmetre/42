/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_list.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpressen <mpressen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/21 20:06:37 by mpressen          #+#    #+#             */
/*   Updated: 2016/01/21 20:07:26 by mpressen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	print_list(t_chain *list)
{
	int	i;
	if (list == NULL)
		ft_error_null("print_list");
	else
		while (list)
		{
			i = -1;
			while (list->tetrimino[++i])
				ft_putendl(list->tetrimino[i]);
			if ((list = list->next))
				ft_putstr("\n");
		}
}
