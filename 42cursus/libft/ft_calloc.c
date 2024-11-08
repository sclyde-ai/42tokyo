/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sclyde <sclyde@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 21:18:51 by sclyde            #+#    #+#             */
/*   Updated: 2024/11/08 11:08:03 by sclyde           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	void *p;
	size_t bytes;

	bytes = nmemb * size;
	if (nmemb == 0 || size == 0)
		return (NULL);
	if (bytes / nmemb != size)
		return (NULL);
	p = malloc(bytes);
	if (p == NULL)
		return (NULL);
	ft_bzero(p, bytes);
	return (p);
}
