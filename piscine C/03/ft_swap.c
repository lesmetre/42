/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpressen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/26 20:33:08 by mpressen          #+#    #+#             */
/*   Updated: 2015/11/26 20:36:58 by mpressen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

void	ft_swap(int *a, int *b)
{
	int tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

int		main(void)
{
	int x;
	int y;
	int *a;
	int *b;

	a = &x;
	b = &y;
	x = 5;
	y = 1;
	ft_swap(a, b);
	printf("%d\n%d\n", x, y);
	return (0);
}
