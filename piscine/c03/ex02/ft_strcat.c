char *ft_strcat(char *dest, char *src)
{
    while(*dest)
        dest++;
    while(*src)
    {
        *dest = *src;
        dest++;
        src++;
    }
    *dest = '\0';
    return dest;
}

#include <stdio.h>

int main()
{
    char dest[100] = "Hello, ";
    char src[] = "World!";

    // ft_strcatを呼び出して文字列を連結
    ft_strcat(dest, src);

    // 結果を出力
    printf("Resulting string: %s\n", dest);

    return 0;
}