/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sclyde <sclyde@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 21:15:03 by sclyde            #+#    #+#             */
/*   Updated: 2024/11/09 15:07:52 by sclyde           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t	dlen;
	size_t	slen;
	size_t	i;

	dlen = ft_strlen(dest);
	slen = ft_strlen(src);
	i = 0;
	if (dlen >= size)
		return (size + slen);
	else if (dlen + slen >= size)
	{
		while (i++ < size - dlen - 1)
			dest[dlen + i - 1] = src[i - 1];
		dest[size - 1] = '\0';
	}
	else
	{
		while (i++ < slen)
			dest[dlen + i - 1] = src[i - 1];
		dest[dlen + slen] = '\0';
	}
	return (dlen + slen);
}
