/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_concat_params.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpressen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/09 03:09:47 by mpressen          #+#    #+#             */
/*   Updated: 2015/12/09 03:40:45 by mpressen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

int		ft_strlen_params(int argc, char **argv)
{
	int i;
	int j;
	int len;

	i = 1;
	len = 0;
	if (argc > 1)
		while (argv[i])
		{
			j = 0;
			while (argv[i][j++])
				   len++;
			i++;
		}
	return (len);
}

char	*ft_concat_params(int argc, char **argv)
{
	char *str;
	int i;
	int j;
	int k;

	i = 1;
	k = 0;
	str = (char *)malloc(sizeof(*str) * ft_strlen_params(argc, argv) + 1);
	while (argv[i])
	{
		j = 0;
		while (argv[i][j])
			str[k++] = argv[i][j++];
		if (argv[i + 1])
			str[k++] = '\n';
		i++;
       }
	str[k] = '\0';
	return (str);
}

int		main(int argc, char **argv)
{
	printf("%s\n", ft_concat_params(argc, argv));
	return (0);
}
