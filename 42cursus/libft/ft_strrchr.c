/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sclyde <sclyde@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 21:14:22 by sclyde            #+#    #+#             */
/*   Updated: 2024/11/07 21:14:23 by sclyde           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	*ans;

	ans = NULL;
	while (*s)
	{
		if (*s == (char)c)
			ans = (char *)s;
		s++;
	}
	if (c == 0)
		return ((char *)s);
	else
		return (ans);
}
