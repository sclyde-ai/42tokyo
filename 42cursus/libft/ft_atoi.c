/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sclyde <sclyde@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 21:19:00 by sclyde            #+#    #+#             */
/*   Updated: 2024/11/07 21:19:01 by sclyde           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *nptr)
{
	int	a;
	int	sign;

	a = 0;
	sign = 1;
	while (ft_isspace(*nptr))
		nptr++;
	if (*nptr == '-')
	{
		nptr++;
		sign *= -1;
	}
	else if (*nptr == '+')
		nptr++;
	while (*nptr && ft_isdigit(*nptr))
	{
		a *= 10;
		a -= *nptr - 48;
		nptr++;
	}
	return (a * sign * -1);
}

// #include <stdio.h>
// #include <limits.h>

// void compare_results(const char *input)
// {
//     int stdlib_result = atoi(input);
//     int ft_result = ft_atoi(input);

//     printf("Input: \"%s\"\n", input);
//     printf("stdlib atoi: %d\n", stdlib_result);
//     printf("my_atoi:    %d\n", ft_result);
//     printf("Match: %s\n", stdlib_result == ft_result ? "YES" : "NO");
//     printf("------------------------\n");
// }

// int main(void)
// {
//     // 様々なテストケース
//     const char *test_cases[] = {
//         "123",              // 基本的な正の整数
//         "-123",             // 負の整数
//         "   456",           // 先頭の空白
//         "+789",             // プラス記号
//         "0",               // ゼロ
//         "2147483647",      // INT_MAX
//         "-2147483648",     // INT_MIN
//         "99999999999",     // オーバーフロー
//         "-99999999999",    // アンダーフロー
//         "abc",             // 無効な入力
//         "123abc",          // 数字+文字
//         "  -42abc",        // 空白+符号+数字+文字
//         "  +  123",        // 複数の空白と符号
//         "",                // 空文字列
//         "  ",              // 空白のみ
//         NULL
//     };

//     int i = 0;
//     while (test_cases[i] != NULL)
//     {
//         compare_results(test_cases[i]);
//         i++;
//     }

//     return (0);
// }
