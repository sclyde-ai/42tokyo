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
    ft_putstr(a[0]);
}