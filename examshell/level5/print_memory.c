/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_memory.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpressen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/19 13:29:36 by mpressen          #+#    #+#             */
/*   Updated: 2016/02/02 17:31:31 by mpressen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	print_hex_mem(unsigned char *addr, size_t size)
{
	size_t	i;
	char	hex[] = "0123456789abcdef";

	i = -1;
	while (++i < 16)
	{
		if (i < size)
		{
			ft_putchar(hex[(int)addr[i] / 16]);
			ft_putchar(hex[(int)addr[i] % 16]);
		}
		else
		{
			ft_putchar(' ');
			ft_putchar(' ');
		}
		if (i % 2)
			ft_putchar(' ');
	}
}

void	print_raw_mem(unsigned char *addr, size_t size)
{
	size_t i;

	i = -1;
	while (++i < size)
	{
		if (addr[i] > 31 && addr[i] < 127)
			ft_putchar(addr[i]);
		else
			ft_putchar('.');
	}
}

void	print_memory(const void *addr, size_t size)
{
	size_t			i;

	i = 0;
	while (size > 16)
	{
		print_hex_mem((unsigned char*)(addr + i), 16);
		print_raw_mem((unsigned char*)(addr + i), 16);
		ft_putchar('\n');
		size -= 16;
		i += 16;

	}
	print_hex_mem((unsigned char*)(addr + i), size);
	print_raw_mem((unsigned char*)(addr + i), size);
	ft_putchar('\n');
}
