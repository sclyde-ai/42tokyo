#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}
void	ft_putstr(char *str)
{
	while (*str)
	{
		write(1, str, 1);
		str++;
	}
}

int	ft_exp(int a, int n)
{
	if (n == 0)
		return (1);
	else
		return (ft_exp(a, n - 1) * a);
}

void ft_sign(int nb)
{
	if (nb < 0)
	{
		ft_putchar('1');
		nb = -nb;
	}
	else
		ft_putchar('0');
}

void ft_put_base_core(int nb, int base, int i)
{;
	char	a;
	char	z;

	z = 0;
	while (i >= 0)
	{
		a = ((nb / ft_exp(base, i)) % base) + 48;
		if (z == 0 && a != 48)
			z = 1;
		if (z)
			write(1, &a, 1);
		i--;
	}
}

void	ft_putnbr(int nb)
{
	int		i;
	char	a;
	char	z;

	if (nb == -2147483648)
	{
		ft_putstr("-2147483648");
		return ;
	}
	if (nb < 0)
	{
		ft_putchar('-');
		nb = -nb;
	}
	z = 0;
	i = 10;
	ft_put_base_core(nb, 10, 11);
}
#include <stdio.h>

void	ft_putnbr2(int nb)
{
	int		i;
	char	a[32];
	char	z;
	int div;

	ft_sign(nb);
	z = 0;
	i = 31;
	div = 2;
	while (i > 0)
	{
		printf("%d ", nb%div);
		printf("%d ", div);
		printf("%d ", nb);
		printf("%s ", "\n");
		a[i] = ((nb / div) % 2) + 48;
		nb -= ((nb / div) % 2);
		nb /= 2;
		// printf("%c ", a);
		// if (z == 0 && a != 48)
		// 	z = 1;
		// if (z)
		// 	write(1, &a, 1);
		i--;
	}
}

void	ft_putnbr8(int nb)
{
	int		i;
	char	a;
	char	z;

	if (nb == -2147483648)
	{
		ft_putstr("20000000000");
		return ;
	}
	ft_sign(nb);
	z = 0;
	i = 15;
	while (i > 0)
	{
		a = ((nb / ft_exp(8, i)) % 8) + 48;
		// printf("%c ", a);
		if (z == 0 && a != 48)
			z = 1;
		if (z)
			write(1, &a, 1);
		i--;
	}
}

void	ft_putnbr16(int nb)
{
	int		i;
	char	a;
	char	z;

	if (nb == -2147483648)
	{
		ft_putstr("80000000");
		return ;
	}
	ft_sign(nb);
	z = 0;
	i = 7;
	while (i > 0)
	{
		a = ((nb / ft_exp(16, i)) % 16) + 48;
		// printf("%c ", a);
		if (z == 0 && a != 48)
			z = 1;
		if (z)
			write(1, &a, 1);
		i--;
	}
}

// void	ft_putnbr2(int nb)
// {
// 	char	a;
// 	char	value[32];
// 	int digit;
// 	int i;

// 	if (nb == -2147483648)
// 	{
// 		return ;
// 	}
// 	if (nb >= 0)
// 		ft_putchar('0');
// 	else
// 	{
// 		ft_putchar('1');
// 	}
    
// 	digit = 2;
// 	i = 0;
// 	while (i <= 32)
// 	{
// 		value[i] = nb%digit + 48;
// 		// nb -= nb%digit;
// 		// printf("%d ", value[i]);
// 		printf("%d ", nb%digit);
// 		printf("%d ", digit);
// 		printf("%d ", nb);
// 		printf("%s ", "\n");
// 		nb /= 2;
// 		digit *= 2;
// 		i++;
// 	}
// 	value[i] = '\0';
// 	// i --;
// 	printf("%s", "\n");
// 	while(digit > 1)
// 	{
// 		// write(1, &value[i], 1);
// 		i--;
// 		digit/=2;
// 	}
// }

void ft_putnbr_base(int nbr, char *base)
{
    
}

int main()
{
	int i;

	i = 0;
	ft_putnbr2(2147483643);
	// while(i < 100)
	// {
	// 	ft_putnbr2(i);
	// 	printf("%s", "\n");
	// 	i++;
	// }

}