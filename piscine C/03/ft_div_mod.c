/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_div_mod.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpressen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/26 20:04:03 by mpressen          #+#    #+#             */
/*   Updated: 2015/11/26 20:11:53 by mpressen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

void	ft_div_mod(int a, int b, int *div, int *mod)
{
	*div = a / b;
	*mod = a % b;
}

int		main(void)
{
	int x;
	int y;
	int *div;
	int *mod;

	div = &x;
	mod = &y;
	ft_div_mod(15, 6, div, mod);
	printf("%d\n%d\n", x, y);
	return (0);
}
