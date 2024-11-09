/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sclyde <sclyde@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 21:18:18 by sclyde            #+#    #+#             */
/*   Updated: 2024/11/09 14:52:18 by sclyde           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_itoa_reverse(size_t n)
{
	char	*p;
	size_t	i;

	p = malloc(11 * sizeof(char));
	if (p == NULL)
		return (NULL);
	i = 0;
	while (n > 0)
	{
		p[i] = n % 10 + 48;
		n /= 10;
		i++;
	}
	while (i < 10)
	{
		p[i] = '\0';
		i++;
	}
	return (p);
}

char	*ft_reverse(char *s)
{
	size_t	i;
	size_t	len;
	char	*p;

	len = ft_strlen(s);
	p = malloc(sizeof(char) * (len + 1));
	if (p == NULL)
		return (NULL);
	i = 0;
	while (i < len)
	{
		p[i] = s[len - i - 1];
		i++;
	}
	p[len] = '\0';
	return (p);
}

char	*ft_itoa(int n)
{
	char		*rev;
	char		*p;
	int			sign;
	long int	long_n;

	long_n = (long int)n;
	if (long_n == 0)
	{
		p = malloc(sizeof(char *));
		*p = '0';
		return (p);
	}
	sign = 0;
	if (long_n < 0)
	{
		long_n *= -1;
		sign = 1;
	}
	rev = ft_itoa_reverse(long_n);
	if (sign)
	{
		rev[ft_strlen(rev)] = '-';
		rev[ft_strlen(rev) + 1] = '\0';
	}
	p = ft_reverse(rev);
	free(rev);
	return (p);
}

// #include <stdio.h>

// int main()
// {
//     printf("%s", ft_itoa(-2147483648));
// }