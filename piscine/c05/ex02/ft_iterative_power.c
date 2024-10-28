int ft_iterative_power(int nb, int power)
{
    int a;

    a = 1;
    if(power < 0)
        return -1;
    while(power > 0)
    {
        a *= nb;
        power--;
    }

    return a;
}
#include <stdio.h>

int main(void)
{
    printf("%d\n",  ft_iterative_power(0, 0));
    printf("%d\n",  ft_iterative_power(0, 1));
    printf("%d\n",  ft_iterative_power(1, 0));
    printf("%d\n",  ft_iterative_power(2, 10));

}