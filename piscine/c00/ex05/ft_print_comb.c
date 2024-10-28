#include <unistd.h>

void ft_print_comb(void)
{
    int a;
    int b;
    int c;

    a = 0;
    b = 0;
    c = 0;
    while(a < 9)
    {
        while(b < 9 && b >= a)
        {
            while(c < 9 && c >= b)
            {
                write(1, &a, 1);
                write(1, &b, 1);
                write(1, &c, 1);
                c++;
            }
            b++;
        }
        a++;
    }
}

int main(void)
{
    char *c;
    char *str = "Hello";
    c = str;  // This is valid

    ft_print_comb();
    write(16, str, 1);
}