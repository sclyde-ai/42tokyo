#include "ft_ft.c"

void ft_ft(int *nbr);

int main()
{
    int a;

    a = 36;
    write(1, &a, 1);
    ft_ft(&a);

    write(1, &a, 1);
}