/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sclyde <sclyde@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 21:18:18 by sclyde            #+#    #+#             */
/*   Updated: 2024/11/07 21:18:19 by sclyde           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_itoa_reverse(size_t n)
{
	char	*temp;
	size_t	i;

	temp = malloc(11 * sizeof(char));
	if (temp == NULL)
		return (NULL);
	i = 0;
	while (n > 0)
	{
		temp[i] = n % 10 + 48;
		n /= 10;
		i++;
	}
	while (i < 10)
	{
		temp[i] = '\0';
		i++;
	}
	return (temp);
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
	char		*a;
	int			sign;
	long int	t;

	t = n;
	if (t == 0)
	{
		a = malloc(sizeof(char *));
		*a = '0';
		return (a);
	}
	sign = 0;
	if (t < 0)
	{
		t *= -1;
		sign = 1;
	}
	rev = ft_itoa_reverse(t);
	if (sign)
	{
		rev[ft_strlen(rev)] = '-';
		rev[ft_strlen(rev) + 1] = '\0';
	}
	a = ft_reverse(rev);
	free(rev);
	return (a);
}

// #include <stdio.h>

// int main()
// {
//     printf("%s", ft_itoa(-2147483648));
// }