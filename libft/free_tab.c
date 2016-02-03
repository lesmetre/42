/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_tab.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpressen <mpressen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/03 21:35:31 by mpressen          #+#    #+#             */
/*   Updated: 2016/02/03 21:45:15 by mpressen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

void	free_tab(char ***tab)
{
	int	i;

	i = -1;
	while ((*tab)[++i])
	{
		free((*tab)[i]);
		(*tab)[i] = NULL;
	}
	free(*tab);
	*tab = NULL;
}
