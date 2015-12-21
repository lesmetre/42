/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpressen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/09 07:52:40 by mpressen          #+#    #+#             */
/*   Updated: 2015/12/10 05:47:31 by mpressen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIST_H
# define LIST_H

typedef struct	s_list
{
	char			*str;
	struct s_list	*next;
}				t_list;

t_list			*add_link(t_list *list, char *str);
void			print_list(t_list *list);

#endif
