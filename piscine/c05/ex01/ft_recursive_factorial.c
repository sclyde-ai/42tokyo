int ft_recursive_factorial(int nb)
{
	if (nb == 0)
		return (1);
	else
		return (ft_recursive_factorial(nb - 1) * nb);
}

#include <stdio.h>

int main(void)
{
    int a;
    a = ft_recursive_factorial(5);
    printf("%d ", a);
}