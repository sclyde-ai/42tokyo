int ft_strncmp(char *s1, char *s2, unsigned int n)
{
	int i;

	i = 0;
	if(n == 0)
		return 0;
	while(*s1 == *s2 && i < n)
	{
		if(*s1 == '\0' || *s2 == '\0')
			return 0;
		s1++;
		s2++;
		i++;
	}
	return(*s1 - *s2);
}

#include <stdio.h>
#include <string.h>

int ft_strncmp(char *s1, char *s2, unsigned int n);

int main()
{
    char *str1 = "HelloWorld";
    char *str2 = "HelloUniverse";
    char *str3 = "Hello";
    char *str4 = "HelLo";

    // Comparing outputs of strncmp and ft_strncmp for different values of n
    printf("strncmp(str1, str2, 5): %d\n", strncmp(str1, str2, 5));
    printf("ft_strncmp(str1, str2, 5): %d\n", ft_strncmp(str1, str2, 5));
    
    printf("strncmp(str1, str3, 5): %d\n", strncmp(str1, str3, 5));
    printf("ft_strncmp(str1, str3, 5): %d\n", ft_strncmp(str1, str3, 5));
    
    printf("strncmp(str1, str4, 5): %d\n", strncmp(str1, str4, 5));
    printf("ft_strncmp(str1, str4, 5): %d\n", ft_strncmp(str1, str4, 5));
    
    printf("strncmp(str1, str2, 0): %d\n", strncmp(str1, str2, 0));
    printf("ft_strncmp(str1, str2, 0): %d\n", ft_strncmp(str1, str2, 0));

    return 0;
}

 