/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_tab.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpressen <mpressen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/03 21:20:23 by mpressen          #+#    #+#             */
/*   Updated: 2016/02/03 21:30:14 by mpressen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	print_tab(char **tab)
{
	int	i;

	i = -1;
	if (!tab)
		ft_error_null("print_tab");
	else
		while (tab[++i])
			ft_putendl(tab[i]);

}
