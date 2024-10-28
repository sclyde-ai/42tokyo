unsigned int ft_strlcpy(char *dest, char *src, unsigned int size)
{
    while(*str){
        if(97 <= *str && 122 >= *str)
            return 1;
        else 
            return 0;
        str++;
    }
}

#include <stdio.h>

int main()
{
    char a[6] = "123456";
    char b[6] = "abcdef";

    printf("%d", ft_str_is_lowcase(a));
	printf("%s", "\n");
	printf("%d", ft_str_is_lowcase(b));
	printf("%s", "\n");
}