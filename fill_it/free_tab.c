/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_tab.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpressen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/28 23:10:03 by mpressen          #+#    #+#             */
/*   Updated: 2016/01/12 07:30:05 by mpressen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	free_tab(char **tab)
{
	int i;

	i = -1;
	while (tab[++i])
	{
		free(tab[i]);
		tab[i] = NULL;
	}
	free(tab);
	tab = NULL;
}