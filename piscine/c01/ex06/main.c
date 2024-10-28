#include "ft_strlen.c"
#include <unistd.h>
#include <stdio.h>

int main(void)
{
    char a[] = "12356";
    int n;
    n = ft_strlen(a);
    printf("%d", n);
}