#include <unistd.h>
#include <stdio.h>

int ft_strlen(char *str)
{
    int n;

    while(1)
    {
        if(*str == '\n')
            return n;
        // write(1, str, 1);
        n++;
        str++;
    }

}