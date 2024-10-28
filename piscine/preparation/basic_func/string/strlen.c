unsigned int 
ft_strlen(char *str)
{
	// for (s = str; *s; ++s);
	int l = 0;
	while(*str != '\0')
	{
		l++;
		str++;
	}
	return(l);
}

#include <stdio.h>

int main()
{
	char *a = "123";
	char *b = "123456";

	printf("Length of string a: %u\n", ft_strlen(a));
	printf("Length of string b: %u\n", ft_strlen(b));
}