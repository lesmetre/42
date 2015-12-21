/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_show_tab.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpressen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/09 05:23:23 by mpressen          #+#    #+#             */
/*   Updated: 2015/12/09 05:33:44 by mpressen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_stock_par.h"

void	ft_print_words_tables(char **tab)
{
	int	i;

	while (tab && *tab)
	{
		i = 0;
		while ((*tab)[i])
			ft_putchar((*tab)[i++]);
		ft_putchar('\n');
		++tab;
	}
}

void	ft_show_tab(struct s_stock_par *par)
{
	int i;

	i = 0;
	while (par[i].str)
	{
		ft_putnbr(par[i].size_param);
		ft_putchar('\n');
		ft_putstr(par[i].str);
		ft_putchar('\n');
		ft_putstr(par[i].copy);
		ft_putchar('\n');
		ft_print_words_tables(par[i].tab);
		i++;
	}
}
