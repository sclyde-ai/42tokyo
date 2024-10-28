/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sclyde <sclyde@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 11:39:14 by sclyde            #+#    #+#             */
/*   Updated: 2024/10/28 11:42:38 by sclyde           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t ft_strlen(const char *c)
{
    size_t l;

    l = 0;
    while(*c++) l++;
    return l;
}

// #include <stdio.h>
// int main()
// {
//     char a = "abcdef";
//     char *char0 = "";

//     printf("%lld\n", ft_strlen(a));
//     printf("%lld\n", ft_strlen(char0));
// }
