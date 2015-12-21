/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_program_name.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpressen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/09 00:21:42 by mpressen          #+#    #+#             */
/*   Updated: 2015/12/09 00:41:39 by mpressen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int		main(int argc, char **argv)
{
	int i;
	int j;

	j = argc;
	if (argc > 2)
		while (--j >= 1)
		{
			i = 0;
			while (argv[j][i])
				ft_putchar(argv[j][i++]);
			ft_putchar('\n'); 
		}
	return (0);
}
