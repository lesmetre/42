/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpressen <mpressen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/24 21:28:58 by mpressen          #+#    #+#             */
/*   Updated: 2016/01/29 09:52:01 by mpressen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# define BUFF_SIZE 1

# include "libft.h"
# include <string.h>
# include <stdlib.h>
# include <unistd.h>
# include <sys/types.h>
# include <sys/uio.h>

typedef struct				s_linked_list
{
	int						fd;
	char					*str;
	struct s_linked_list	*next;
	struct s_linked_list	*prev;
}							t_linked_list;

int							get_next_line(int const fd, char **line);

#endif
