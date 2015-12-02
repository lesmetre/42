/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpressen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/01 00:58:00 by mpressen          #+#    #+#             */
/*   Updated: 2015/12/01 01:19:30 by mpressen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strstr(const char *s1, const char *s2)
{
	size_t	count1;
	size_t	count2;

	count1 = 0;
	count2 = 0;
	if (!(*s2))
		return ((char *)s1);
	while (s1[count1])
	{
		if (s1[count1] == s2[count2])
		{
			while (s1[count1 + count2] == s2[count2])
			{
				count2++;
			}
			if (s2[count2] == '\0')
			{
				return ((char *)s1 + count1);
			}
		}
		count2 = 0;
		count1++;
	}
	return (NULL);
}
