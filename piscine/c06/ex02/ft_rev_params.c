#include <unistd.h>

void	ft_putstr(char *str)
{
	while (*str)
	{
		write(1, str, 1);
		str++;
	}
}

int main(int n, char** a)
{
    int i;

    i = n;
    while(i > 0)
    {
        ft_putstr(a[i]);
        write(1, '\n', 1);
        i--;
    }
}