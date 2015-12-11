/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpressen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/05 00:49:41 by mpressen          #+#    #+#             */
/*   Updated: 2015/12/11 03:46:12 by mpressen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strmapi(char const *s, char (*f) (unsigned int, char))
{
	char			*str;
	unsigned int	i;

	i = 0;
	if (!(s) || !(f) || !(*s) || !(*f))
	{
		ft_putendl("\033[31merror: ft_strmapi : null parameter\033[0m");
		return (NULL);
	}
	str = (char *)malloc(sizeof(*str) * (ft_strlen(s) + 1));
	if (str)
	{
		while (s[i])
		{
			str[i] = f(i, s[i]);
			i++;
		}
		str[i] = '\0';
		return (str);
	}
	ft_putendl("\033[31merror : ft_strmapi : malloc failed\033[0m");
	return (NULL);
}
