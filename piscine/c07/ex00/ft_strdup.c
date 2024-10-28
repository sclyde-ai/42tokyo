#include <stdlib.h>

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

char *ft_strcpy(char *dest, char *src)
{
    int i;

    i = 0;
    while(src[i])
    {
        dest[i] = src[i];
        i++;
    }
    dest[i] = '\0';
    return dest;
}

char *ft_strdup(char *src)
{
    int l;
    char* c;
    l = ft_strlen(src);
    c = (char*)malloc(sizeof(char) * (l+1));
	if(!c)
        return NULL;
	ft_strcpy(c, src);
	return c;
}

#include <stdio.h>
#include <string.h> // For strdup
#include <stdlib.h> // For malloc and free

int main(void)
{
    char *original = "Hello, world!";
    char *lib_dup;
    char *ft_dup;

    // Using standard library strdup
    lib_dup = strdup(original);

    // Using custom ft_strdup
    ft_dup = ft_strdup(original);

    // Output the results
    printf("Original: %s\n", original);
    printf("strdup: %s\n", lib_dup);
    printf("ft_strdup: %s\n", ft_dup);

    // Free the allocated memory
    free(lib_dup);
    free(ft_dup);

    return 0;
}
