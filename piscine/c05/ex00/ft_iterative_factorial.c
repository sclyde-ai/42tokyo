int ft_iterative_factorial(int nb)
{
    int i;
    int f;
    int g;

    i = 0;
    f = 1;
    g = 1;
    while(i < nb)
    {
        f *= g;
        g++;
        i++;
    }

    return f;
}

#include <stdio.h>

int main(void)
{
    int a;
    a = ft_iterative_factorial(5);
    printf("%d ", a);
}