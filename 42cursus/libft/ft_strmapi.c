/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sclyde <sclyde@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 21:14:44 by sclyde            #+#    #+#             */
/*   Updated: 2024/11/08 16:24:12 by sclyde           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*p;
	char	*t;
	size_t	l;
	unsigned int	i;

	l = ft_strlen(s);
	p = malloc(sizeof(char *) * (l + 1));
	if(p == NULL)
		return NULL;
	t = p;
	i = 0;
	while (*s)
		*p++ = f(i++, *s++);
	return (t);
}
