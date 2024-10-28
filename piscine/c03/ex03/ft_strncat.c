char *ft_strncat(char *dest, char *src, unsigned int n)
{
    int i;

    i = 0;
    while(*dest)
        dest++;
    while(i < n && src[i] != '\0')
    {
        dest[i] = src[i];
        i++;
    }
    dest[i] = '\0';
    return dest;
}

#include <stdio.h>
#include <string.h>

int main(void)
{
    // 文字列配列の作成
    char dest1[50] = "Hello, ";
    char dest2[50] = "Hello, ";
    char src[] = "World!";
    unsigned int n = 3;

    // 標準strncat関数の使用
    strncat(dest1, src, n);
    // 自作のft_strncat関数の使用
    ft_strncat(dest2, src, n);

    // 結果を表示
    printf("strncat:    %s\n", dest1);   // 標準ライブラリの結果
    printf("ft_strncat: %s\n", dest2);   // 自作の結果

    return 0;
}