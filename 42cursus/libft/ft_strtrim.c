/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sclyde <sclyde@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 21:19:49 by sclyde            #+#    #+#             */
/*   Updated: 2024/11/08 10:55:48 by sclyde           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*p;
	char	*start;
	int		b;
	size_t	i;

	p = (char *)malloc(ft_strlen(s1) + 1);
	if (p == NULL)
		return (NULL);
	start = p;
	while (*s1)
	{
		i = 0;
		b = 0;
		while (i < ft_strlen(set))
		{
			if (*s1 == set[i])
				b = 1;
			i++;
		}
		if (b)
			s1++;
		else
			*p++ = *s1++;
	}
	*p++ = '\0';
	return (start);
}
