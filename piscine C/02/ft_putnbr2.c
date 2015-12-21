/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpressen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/26 01:26:25 by mpressen          #+#    #+#             */
/*   Updated: 2015/11/26 01:56:48 by mpressen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putnbr(int nb)
{
	int temp;
	int size;

	size = 1;
	if (nb < 0)
	{
		ft_putchar('-');
		nb = -nb;
	}
	temp = nb;
	while (temp / 10 >= 1)
	{
		size *= 10;
		temp /= 10;
	}
	temp = nb;
	while (size)
	{
		ft_putchar(temp / size + '0');
		temp %= size;
		size /= 10;
	}
}

int		main(void)
{
	ft_putnbr(80);
	return (0);
}
