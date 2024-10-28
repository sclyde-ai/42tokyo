
char     *ft_str_is_strupcase (char *str)
{
    while(*str){
        if(97 <= *str && 122 >= *str)
            *str = *str - 32;
        str++;
    }
    return str;
}

#include <stdio.h>

int main()
{
    char a[6] = "abcdef";

    printf("%s", a);
	printf("%s", "\n");
    ft_str_is_strupcase(a);
	printf("%s", a);
	printf("%s", "\c");
}