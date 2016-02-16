/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpressen <mpressen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/16 04:02:07 by mpressen          #+#    #+#             */
/*   Updated: 2016/02/16 06:07:22 by mpressen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "libft.h"

int		main(int ac, char **av)
{
	t_fdf	*param;

	param = NULL;
	if (ft_parsing(ac, av, &param))
		return (1);
	return (0);
}
