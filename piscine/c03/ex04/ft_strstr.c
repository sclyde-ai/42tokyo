#include <unistd.h>

int	ft_strlen(char *str)
{
	int	n;

	n = 0;
	while (*str)
	{
		n++;
		str++;
	}
	return (n);
}

int ft_strcmp(char *s1, char *s2)
{
	while(*s1 == *s2)
	{
		if(*s1 == '\0' || *s2 == '\0')
			return 0;
		s1++;
		s2++;
	}
	return(*s1 - *s2);
}

char *ft_strstr(char *str, char *to_find)
{
    int i;
    char a;

    if(*to_find == '\0')
        return str;

    while(*str)
    {
        i = 0;
        a = 1;
        while(to_find[i] != '\0')
        {
            if(str[i] != to_find[i])
                a = 0;
            i++;
        }
        if(a)
            return str;
        str++;
    }
    return NULL;

}

#include <stdio.h>
#include <string.h>

int main()
{
    char str[] = "Hello, World!";
    char to_find[] = "llo";

    // 標準のstrstr関数の出力
    char *result_std = strstr(str, to_find);
    printf("Standard strstr: %s\n", result_std);

    // 修正したft_strstr関数の出力
    char *result_ft = ft_strstr(str, to_find);
    printf("Custom ft_strstr: %s\n", result_ft);

    return 0;
}