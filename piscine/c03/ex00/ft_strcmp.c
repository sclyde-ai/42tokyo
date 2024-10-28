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

#include <stdio.h>
#include <string.h>

int ft_strcmp(char *s1, char *s2);

int main()
{
    char *str1 = "Hello";
    char *str2 = "Hello";
    char *str3 = "Hell";
    char *str4 = "HelLo";
    
    // Comparing outputs of strcmp and ft_strcmp
    printf("strcmp(str1, str2): %d\n", strcmp(str1, str2));
    printf("ft_strcmp(str1, str2): %d\n", ft_strcmp(str1, str2));
    
    printf("strcmp(str1, str3): %d\n", strcmp(str1, str3));
    printf("ft_strcmp(str1, str3): %d\n", ft_strcmp(str1, str3));

    printf("strcmp(str1, str4): %d\n", strcmp(str1, str4));
    printf("ft_strcmp(str1, str4): %d\n", ft_strcmp(str1, str4));

    return 0;
}
