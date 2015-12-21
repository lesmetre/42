/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpressen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/19 18:34:22 by mpressen          #+#    #+#             */
/*   Updated: 2015/12/19 18:35:05 by mpressen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include <stdlib.h>

int		is_not_space(char c)
{
	return (c != '\t' && c != ' ' && c != '\n');
}

int		ft_countbits(char *str)
{
	int i;
	int bits;
	int is_bit;

	i = 0;
	bits = 0;
	is_bit = 0;
	while (str[i])
	{
		if (is_not_space(str[i]) && is_bit == 0)
		{
			is_bit = 1;
			bits++;
		}
		if (!(is_not_space(str[i])) && is_bit == 1)
			is_bit = 0;
		while (str[i] && !(is_not_space(str[i])) && is_bit == 0)
			i++;
		while (str[i] && is_not_space(str[i]) && is_bit == 1)
			i++;
	}
	return (bits);
}

char	*ft_strsub(char *str, int start, int size)
{
	char	*sub;
	int		i;

	i = 0;
	sub = 0;
	if ((sub = (char *)malloc(sizeof(*sub) * size + 1)))
	{
		while (i < size)
		{
			sub[i] = str[start + i];
			i++;
		}
		sub[i] = '\0';
		return (sub);
	}
	return (0);
}

char	**ft_split(char *str)
{
	char	**split;
	int		i;
	int		start;
	int		end;
	int		j;

	i = 0;
	j = 0;
	if (!(str))
		return (NULL);
	if ((split = (char **)malloc(sizeof(*split) * (ft_countbits(str) + 1))))
	{
		while (str[i])
		{
			while (str[i] && !(is_not_space(str[i])))
				i++;
			start = i;
			while (str[i] && is_not_space(str[i]))
				i++;
			end = i;
			if (end > start)
				split[j++] = ft_strsub(str, start, end - start);
		}
		split[j] = NULL;
		return (split);
	}
	return (NULL);
}
