/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpressen <mpressen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/21 20:57:40 by mpressen          #+#    #+#             */
/*   Updated: 2016/04/21 20:59:38 by mpressen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		ft_error(int error, char *str)
{
	if (error == 1)
		ft_putendl_fd("Usage : ./fdf <filename> [ case_size z_size ]", 2);
	else if (error == 2)
	{
		ft_putstr_fd("no file ", 2);
		ft_putstr_fd(str, 2);
		ft_putstr_fd("\n", 2);
	}
	else if (error == 3)
		ft_putendl_fd("Found wrong line length. Exiting.", 2);
	else if (error == 4)
		ft_putendl_fd("No data found.", 2);
	return (1);
}
