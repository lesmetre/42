/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_tab.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpressen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/28 23:10:03 by mpressen          #+#    #+#             */
/*   Updated: 2016/01/22 18:44:43 by mpressen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

/*void	free_tab(char ***add_tab)
{
	int i;

	i = -1;
	while ((*add_tab)[++i])
		ft_strdel(&(*add_tab)[i]);
	free(*add_tab);
	*add_tab = NULL;
	
	}*/
void	free_tab(char **tab)
{
	int i;

	i = -1;
	while (tab[++i])
		ft_strdel(&tab[i]);
	free(&tab);
	tab = NULL;
}

