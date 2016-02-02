/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strclr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpressen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/27 22:02:32 by mpressen          #+#    #+#             */
/*   Updated: 2016/02/02 22:16:47 by mpressen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** The ft_strclr() set character's value from a string to 0.
*/

void	ft_strclr(char *s)
{
	ft_bzero((void*)s, ft_strlen(s));
}
