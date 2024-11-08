/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap1.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sclyde <sclyde@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 21:14:44 by sclyde            #+#    #+#             */
/*   Updated: 2024/11/08 11:05:52 by sclyde           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap1(char const *s, char (*f)(unsigned int, char))
{
	char *p;
	char *t;
	size_t l;
	unsigned int i;

	l = ft_strlen(s);
	p = malloc(sizeof(char *) * (l + 1));
	t = p;
	while (*s)
		*p++ = f(i++, *s++);
	return t;
}