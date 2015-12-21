/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpressen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/26 00:28:32 by mpressen          #+#    #+#             */
/*   Updated: 2015/11/26 01:07:35 by mpressen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_print_solutions(char w, char x, char y, char z)
{
	ft_putchar(w);
	ft_putchar(x);
	ft_putchar(' ');
	ft_putchar(y);
	ft_putchar(z);
}

void	ft_print_comb2(void)
{
	char w;
	char x;
	char y;
	char z;

	w = '0';
	while (w <= '9')
	{
		x = '0';
		while (x <= '9')
		{
			y = '0';
			while (y <= '9')
			{
				z = '0';
				while (z <= '9')
				{
					if (w < y || (w == y && x < z))
					{
						ft_print_solutions(w, x, y, z);
						if (w != '9' || x != '8')
						{
							ft_putchar(',');
							ft_putchar(' ');
						}
					}
					z++;
				}
				y++;
			}
			x++;

		}
		w++;
	}
}

int		main(void)
{
	ft_print_comb2();
	return (0);
}
