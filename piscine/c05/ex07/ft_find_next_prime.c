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

int ft_find_next_prime(int nb)
{
    int i;

    i = nb;
    while(1)
    {
        if(ft_is_prime)
            return i;
        i++;
    }
}

#include <stdio.h>

int main(void)
{
    printf("%d", ft_find_next_prime(78677548));
}