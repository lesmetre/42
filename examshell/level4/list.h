/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zaz <zaz@staff.42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/27 13:14:10 by zaz               #+#    #+#             */
/*   Updated: 2015/12/18 18:29:09 by mpressen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIST_H
# define LIST_H

typedef struct s_list t_list;

struct s_list
{
	int     data;
	t_list  *next;
};

int			croissant(int a, int b);
t_list		*sort_list(t_list *lst, int (*cmp)(int, int));
void		print_list(t_list *list);
t_list		*add_link(t_list *list, int d);

#endif
