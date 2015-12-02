/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpressen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/30 23:58:49 by mpressen          #+#    #+#             */
/*   Updated: 2015/12/01 00:57:12 by mpressen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strncat(char *s1, const char *s2, size_t n)
{
	size_t count1;
	size_t count2;

	count1 = 0;
	count2 = 0;
	while (s1[count1])
		count1++;
	while (s2[count2] && n > 0)
	{
		s1[count1] = s2[count2];
		count1++;
		count2++;
		n--;
	}
	s1[count1] = '\0';
	return (s1);
}
