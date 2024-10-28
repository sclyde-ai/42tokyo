int ft_recursive_power(int nb, int power)
{
    if(power == 0)
        return 1;
    else if(power < 0)
        return -1;
    else
        return ft_recursive_power(nb, power-1) * nb;
}
#include <stdio.h>

int main(void)
{
    printf("%d\n",  ft_recursive_power(0, 0));
    printf("%d\n",  ft_recursive_power(0, 1));
    printf("%d\n",  ft_recursive_power(1, 0));
    printf("%d\n",  ft_recursive_power(2, 10));

}