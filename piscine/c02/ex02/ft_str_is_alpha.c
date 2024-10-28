int     ft_str_is_alpha (char *str)
{
    while(*str){
        if((65 <= *str && 90 >= *str) || (97 <= *str && 122 >= *str))
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

    printf("%d", ft_str_is_alpha(a));
	printf("%s", "\n");
	printf("%d", ft_str_is_alpha(b));
	printf("%s", "\n");
}