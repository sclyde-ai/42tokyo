char *ft_strcpy(char *dest, char *src)
{
    int i;

    i = 0;
    while(src[i])
    {
        dest[i] = src[i];
        i++;
    }
    dest[i] = '\0';
    return dest;
}

#include <string.h>

int main()
{
    char a[7] = "123456";
    char b[4] = "abc";
    ft_strcpy(a, b);
    printf(a);
    printf("\n");
    char c[7] = "123456";
    char d[4] = "abc";
    strcpy(c, d);
    printf(c);
    printf("\n");

    char e[7] = "123456";
    char f[4] = "abc";
    ft_strcpy(f, e);
    printf(f);
    printf("\n");
    char g[7] = "123456";
    char h[4] = "abc";
    strcpy(h, g);
    printf(h);
    printf("\n");
}