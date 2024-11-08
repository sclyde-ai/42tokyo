/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sclyde <sclyde@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 21:16:52 by sclyde            #+#    #+#             */
/*   Updated: 2024/11/07 21:26:34 by sclyde           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *s, int c, size_t size)
{
	unsigned char	*p;

	p = (unsigned char *)s;
	while (size--)
	{
		*p = (unsigned char)c;
		p++;
	}
	return (s);
}
