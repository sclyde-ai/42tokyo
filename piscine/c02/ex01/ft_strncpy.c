#include <stdio.h>
#include <unistd.h>
#include <string.h>

char *ft_strncpy(char *dest, char *src, unsigned int n)
{
    int i;

    i = 0;
    while(i < n && src[i] != '\0')
    {
        dest[i] = src[i];
        i++;
    }
}

int main()
{
    // dest > src && src > n
    char a[7] = "123456";
    char b[4] = "abc";
    ft_strncpy(a, b, 2);
    printf("%s", a);
    printf("%s", "\n");
    char c[7] = "123456";
    char d[4] = "abc";
    strncpy(c, d, 2);
    printf("%s", c);
    printf("%s", "\n");

    // dest > src && src < n && dest > n
    char a2[7] = "123456";
    char b2[4] = "abc";
    ft_strncpy(a2, b2, 8);
    printf("%s", a2);
    printf("%s", "\n");
    char c2[7] = "123456";
    char d2[4] = "abc";
    strncpy(c2, d2, 8);
    printf("%s", c2);
    printf("%s", "\n");

    // dest > src && src < n && dest < n
    char a3[7] = "123456";
    char b3[4] = "abc";
    ft_strncpy(a3, b3, 5);
    printf("%s", a3);
    printf("%s", "\n");
    char c3[7] = "123456";
    char d3[4] = "abc";
    strncpy(c3, d3, 5);
    printf("%s", c3);
    printf("%s", "\n");

    // dest < src && src > n && dest > n
    char e[7] = "123456";
    char f[4] = "abc";
    ft_strncpy(f, e, 2);
    printf("%s", f);
    printf("%s", "\n");
    char g[7] = "123456";
    char h[4] = "abc";
    strncpy(h, g, 2);
    printf("%s", h);
    printf("%s", "\n");

    // dest < src && src < n
    char e2[7] = "123456";
    char f2[4] = "abc";
    ft_strncpy(f2, e2, 8);
    printf("%s", f2);
    printf("%s", "\n");
    char g2[7] = "123456";
    char h2[4] = "abc";
    strncpy(h2, g2, 8);
    printf("%s", h2);
    printf("%s", "\n");

    // dest < src && src > n && dest < n
    char e3[7] = "123456";
    char f3[4] = "abc";
    ft_strncpy(f3, e3, 5);
    printf("%s", f3);
    printf("%s", "\n");
    char g3[7] = "123456";
    char h3[4] = "abc";
    strncpy(h3, g3, 5);
    printf("%s", h3);
    printf("%s", "\n");
}