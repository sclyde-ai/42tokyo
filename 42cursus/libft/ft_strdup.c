/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sclyde <sclyde@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 21:25:33 by sclyde            #+#    #+#             */
/*   Updated: 2024/11/07 21:25:34 by sclyde           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	char	*p;
	char	*first;

	if (s == NULL)
		return (NULL);
	p = (char *)malloc(ft_strlen(s) * sizeof(char) + 1);
	if (p == NULL)
		return (NULL);
	first = p;
	while (*s)
		*p++ = *s++;
	*p = '\0';
	return (first);
}
