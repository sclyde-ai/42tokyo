/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sclyde <sclyde@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 21:14:33 by sclyde            #+#    #+#             */
/*   Updated: 2024/11/09 14:32:10 by sclyde           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	unsigned char	*s1_;
	unsigned char	*s2_;

	s1_ = (unsigned char *)s1;
	s2_ = (unsigned char *)s2;
	while (n-- > 0)
	{
		if (*s1_ != *s2_)
			return ((int)(*s1_ - *s2_));
		s1_++;
		s2_++;
	}
	return (0);
}

// #include <stdio.h>
// #include <string.h>
// #include "libft.h"

// int main()
// {
//     const char *s1 = "\0";
//     const char *s2 = "\200";
//     size_t n = 5;  // 比較する文字数

//     int result_ft = ft_strncmp(s1, s2, n);
//     int result_std = strncmp(s1, s2, n);

//     printf("ft_strncmp result: %d\n", result_ft);
//     printf("strncmp result: %d\n", result_std);

//     if (result_ft == result_std)
//         printf("Both functions returned the same result.\n");
//     else
//         printf("The functions returned different results.\n");

//     return (0);
// }
