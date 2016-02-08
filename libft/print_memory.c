/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_memorytest.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpressen <mpressen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/08 20:20:20 by mpressen          #+#    #+#             */
/*   Updated: 2016/02/08 21:46:15 by mpressen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "libft.h"

static void		print_hexa(unsigned char *addr, size_t size)
{
	unsigned char	*hex;
	size_t			i;

	hex = (unsigned char*)"0123456789abcdef";
	i = -1;
	while (++i < 16)
	{
		if (i < size)
		{
			ft_putchar((char)hex[(int)addr[i] / 16]);
			ft_putchar((char)hex[(int)addr[i] % 16]);
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

static void		print_raw(unsigned char *addr, size_t size)
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
	ft_putchar('\n');
}

void			print_memory(const void *addr, size_t size)
{
	size_t i;

	i = 0;
	while (size > 16)
	{
		print_hexa((unsigned char*)addr + i, 16);
		print_raw((unsigned char*)addr + i, 16);
		size -= 16;
		i += 16;
	}
	print_hexa((unsigned char*)addr + i, size);
	print_raw((unsigned char*)addr + i, size);
}
