/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpressen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/01 03:27:06 by mpressen          #+#    #+#             */
/*   Updated: 2015/12/01 03:33:20 by mpressen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_atoi(const char *str)
{
	size_t	count;
	int		res;
	int		sign;

	count = 0;
	res = 0;
	sign = 1;
	while (str[count] == '\n' || str[count] == '\f' || str[count] == '\r'
		|| str[count] == "\v" || str[count] == " " || str[count] == "\t")
		count++;
	if (str[count] == '-' || str[count] == '+')
	{
		if (str[count] == '-')
			sign = -1;
		count++;
	}
	while (str[count] >= '0' && str[count] <= '9')
	{
		res = res * 10 + str[count] - '0';
		count++;
	}
	return (res * sign);
}
