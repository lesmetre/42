/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpressen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/28 03:11:21 by mpressen          #+#    #+#             */
/*   Updated: 2015/12/02 21:46:29 by mpressen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_memcmp(const void *s1, const void *s2, size_t n)
{
	const char	*s11;
	const char	*s22;
	size_t		count;

	s11 = s1;
	s22 = s2;
	count = 0;
	while (count < n)
	{
		if (s11[count] != s22[count])
			return (s11[count] - s22[count]);
		count++;
	}
	return (0);
}
