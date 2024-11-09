/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sclyde <sclyde@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/09 12:31:08 by sclyde            #+#    #+#             */
/*   Updated: 2024/11/09 13:39:30 by sclyde           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	char	c;

	if (n == -2147483648)
	{
		write(fd, "-2147483648", 11);
		return ;
	}
	if (n < 0)
	{
		write(fd, "-", 1);
		n = -n;
	}
	if (n >= 10)
		ft_putnbr_fd(n / 10, fd);
	c = (n % 10) + '0';
	write(fd, &c, 1);
}

// #include <fcntl.h> // For open
// #include <stdio.h> // For printf

// int main(void)
// {
//     int fd = open("output.txt", O_WRONLY | O_CREAT | O_TRUNC, 0644);
//     if (fd < 0)
//     {
//         perror("open");
//         return (1);
//     }

//     ft_putnbr_fd(12345, fd);
//     ft_putnbr_fd(-9876, fd);
//     ft_putnbr_fd(0, fd);
//     ft_putnbr_fd(-2147483648, fd);

//     close(fd);

//     printf("Output written to output.txt\n");

//     return (0);
// }
