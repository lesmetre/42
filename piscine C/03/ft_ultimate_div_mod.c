/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultimate_div_mod.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpressen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/26 20:12:46 by mpressen          #+#    #+#             */
/*   Updated: 2015/11/26 20:20:01 by mpressen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

void	ft_ultimate_div_mod(int *a, int *b)
{
	int temp;

	temp = *a;
	*a = temp / *b;
	*b = temp % *b;
}

int		main(void)
{
	int x;
	int y;
	int *a;
	int *b;

	a = &x;
	b = &y;
	x = 15;
	y = 6;
	ft_ultimate_div_mod(a, b);
	printf("%d\n%d\n", x, y);
	return (0);
}
