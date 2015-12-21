/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_eight_queens_puzzle_2.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpressen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/27 18:58:39 by mpressen          #+#    #+#             */
/*   Updated: 2015/11/27 19:42:44 by mpressen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>

void	create_tab_with_points(void)
{
	int		line;
	int		column;


	column = 0;
	while (column <= 7)
	{
		line = 0;
		while (line <= 7)
		{
			printf(".");
			line++;
		}
		printf("\n");
		column++;
	}
}

int		main(void)
{
	create_tab_with_points();
	return (0);
}
