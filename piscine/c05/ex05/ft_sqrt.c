int ft_sqrt(int nb)
{
    int n;
    int a;

    a = 0;
    n = 1;
    while(n*n <= nb)
    {
        if(n*n == nb)
            a = n;
        n++;
    }
    return a;
}

#include <stdio.h>

int main()
{
    printf("%d", ft_sqrt(68));
}