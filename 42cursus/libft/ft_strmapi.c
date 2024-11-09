/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sclyde <sclyde@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 21:14:44 by sclyde            #+#    #+#             */
/*   Updated: 2024/11/09 15:09:27 by sclyde           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char			*p;
	char			*t;
	size_t			l;
	unsigned int	i;

	if (s == NULL || f == NULL)
		return (NULL);
	l = ft_strlen(s);
	p = malloc(sizeof(char *) * (l + 1));
	if (p == NULL)
		return (NULL);
	t = p;
	i = 0;
	while (*s)
		*p++ = f(i++, *s++);
	return (t);
}
