int ft_is_prime(int nb)
{
    int n;
    int a;

    n = 2;
    a = 1;
    while(n*n <= nb)
    {
        if(nb%n == 0)
            a = 0;
        n++;
    }
    return a;
}

#include <stdio.h>

int main(void)
{
    printf("%d", ft_is_prime(4));
}