/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sclyde <sclyde@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 21:16:35 by sclyde            #+#    #+#             */
/*   Updated: 2024/11/07 21:22:37 by sclyde           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

size_t	ft_split_number(const char *s, char c)
{
	int		nullornot;
	size_t	num;

	num = 0;
	nullornot = 1;
	while (*s)
	{
		if (*s != c)
		{
			if (nullornot)
				num++;
			nullornot = 0;
		}
		else
			nullornot = 1;
		s++;
	}
	return (num);
}

size_t	ft_split_strlen(const char *s, char c)
{
	size_t	l;

	l = 0;
	while (*s != c && *s != '\0')
	{
		l++;
		s++;
	}
	return (l);
}

char	*ft_split_strdup(const char *s, char c)
{
	char	*p;
	char	*first;

	if (s == NULL)
		return (NULL);
	p = (char *)malloc(ft_split_strlen(s, c) * sizeof(char) + 1);
	if (p == NULL)
		return (NULL);
	first = p;
	while (*s != c && *s != '\0')
		*p++ = *s++;
	*p = '\0';
	return (first);
}

void	free_split(char **split, size_t num)
{
	size_t	i;

	i = 0;
	while (i < num)
	{
		free(split[i]);
		i++;
	}
	free(split);
}

char	**ft_split(char const *s, char c)
{
	char	**split;
	size_t	num;
	size_t	i;
	size_t	len;

	if (s == NULL)
		return (NULL);
	num = ft_split_number(s, c);
	split = malloc(sizeof(char *) * (num + 1));
	if (split == NULL)
		return (NULL);
	i = 0;
	while (i < num)
	{
		while (*s == c)
			s++;
		len = ft_split_strlen(s, c);
		split[i] = ft_split_strdup(s, c);
		if (split[i] == NULL)
		{
			free_split(split, i);
			return (NULL);
		}
		s += len;
		i++;
	}
	split[i] = NULL;
	return (split);
}

// #include <stdio.h>
// #include <string.h>
// #include <stdlib.h>

// // ft_split の実装はここに配置

// void print_split_result(char **result)
// {
//     int i = 0;
//     while (result[i] != NULL)
//     {
//         printf("'%s'\n", result[i]);
//         i++;
//     }
//     printf("---\n");
// }

// void free_split_result(char **result)
// {
//     int i = 0;
//     while (result[i] != NULL)
//     {
//         free(result[i]);
//         i++;
//     }
//     free(result);
// }

// void test_ft_split(const char *str, char c, const char *test_name)
// {
//     printf("Test: %s\n", test_name);
//     printf("Input string: \"%s\"\n", str);
//     printf("Delimiter: '%c'\n", c);
//     printf("Result:\n");

//     char **result = ft_split(str, c);
//     print_split_result(result);
//     free_split_result(result);
// }

// int main()
// {
//     // テストケース1: 基本的な分割
//     test_ft_split("hello world", ' ', "Basic splitting");

//     // テストケース2: 複数の区切り文字が連続する場合
//     test_ft_split("hello   world", ' ', "Multiple spaces");

//     // テストケース3: 空の文字列
//     test_ft_split("", ' ', "Empty string");

//     // テストケース4: 区切り文字で始まる場合
//     test_ft_split(" hello world", ' ', "Starting with delimiter");

//     // テストケース5: 区切り文字で終わる場合
//     test_ft_split("hello world ", ' ', "Ending with delimiter");

//     // テストケース6: 1文字の文字列
//     test_ft_split("a", ' ', "Single character");

//     // テストケース7: 区切り文字のみの文字列
//     test_ft_split("   ", ' ', "Only delimiters");

//     // テストケース8: カンマを区切り文字として使用
//     test_ft_split("one,two,three", ',', "Comma as delimiter");

//     // テストケース9: 長い文字列の分割
//     test_ft_split("This is a very long string that needs to be split", ' ',
//                   "Long string");

//     // テストケース10: 数字を含む文字列
//     test_ft_split("123 456 789", ' ', "Numbers");

//     return (0);
// }