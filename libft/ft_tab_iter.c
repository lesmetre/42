/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tab_iter.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpressen <mpressen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/17 10:17:41 by mpressen          #+#    #+#             */
/*   Updated: 2016/02/17 11:01:39 by mpressen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "stdlib.h"

void	**ft_tab_iter(void **tab, void *(*f)(void *))
{
	int		i;
	int		indexlen;
	void	**dst;

	ft_putendl("on rentre dans ft_tab_iter");
	if (!tab || !f)
	{
		ft_error_null("ft_tab_iter");
		return (NULL);
	}
	i = -1;
	indexlen = ft_indexlen(tab);
	if (!(dst = (void **)malloc(sizeof(*dst) * indexlen + 1)))
	{
		ft_error_malloc("ft_tab_iter");
		return (NULL);
	}
	while (indexlen)
		dst[indexlen--] = 0;
	dst[0] = 0;
	while (tab[++i])
		dst[i] = f(tab[i]);
	return (dst);
}
