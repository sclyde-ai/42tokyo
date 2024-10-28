#include <unistd.h>

void ft_exp(int a, int n)
{
    if(n == 0)
    {
        return 1;
    }
    else
    {
        return ft_exp(n-1)*a;
    }

}

void ft_putnbr()
{
    int a;
    int n;

}