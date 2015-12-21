/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpressen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/09 07:05:23 by mpressen          #+#    #+#             */
/*   Updated: 2015/12/09 07:14:18 by mpressen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_is_sort(int *tab, int length, int (*f) (int, int))
{
	int i;

	i = 0;
	while (i + 1 < length)
	{
		if (f(tab[i], tab[i + 1]) <= 0)
			i++;
		else
			i = length;
	}
	if (i = length - 1)
		return (1);
	i = 0;
	while (i + 1 < length)
	{
		if (f(tab[i], tab[i + 1]) >= 0)
			i++;
		else
			i = length;
	}
	if (i = length - 1)
		return (1);
	return (0);
}
