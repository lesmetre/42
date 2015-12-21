/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpressen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/25 23:55:34 by mpressen          #+#    #+#             */
/*   Updated: 2015/11/26 00:19:50 by mpressen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_print_solution(char x, char y, char z)
{
	ft_putchar(x);
	ft_putchar(y);
	ft_putchar(z);
}

void	ft_print_comb(void)
{
	char x;
	char y;
	char z;

	x = '0';
	while (x <= '7')
	{
		y = x + 1;
		while(y <= '8')
		{
			z = y + 1;
			while (z <= '9')
			{
				ft_print_solution(x, y, z);
				if ((x != '7') || (y != '8') || (z != '9'))
				{
					ft_putchar(',');
					ft_putchar(' ');
				}
				z++;
			}
			y++;
		}
		x++;
	}
}

int		main(void)
{
	ft_print_comb();
	return (0);
}
