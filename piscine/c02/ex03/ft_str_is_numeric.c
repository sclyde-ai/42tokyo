int     ft_str_is_numeric (char *str)
{
    while(*str){
        if(48 <= *str && 57 >= *str)
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

    printf("%d", ft_str_is_numeric(a));
	printf("%s", "\n");
	printf("%d", ft_str_is_numeric(b));
	printf("%s", "\n");
}