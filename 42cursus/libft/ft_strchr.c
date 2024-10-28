#include "libft.h"

char *ft_strchr(const char *s, int c)
{
    char *p;

    p = (char *)s;
    while(*p)
    {
        if(*p == (char)c) return p;
        p++;
    }

    if((char)c == '\0')
        return p;
    else
        return NULL;
}


// #include <stdio.h>
// #include <string.h>

// // char *ft_strchr(const char *s, int c);

// int main() {
//   // Test cases
//   char str1[] = "Hello, world!";
//   char str2[] = "";
//   char str3[] = "This is a test string.";

//   // Test 1: Find 'o' in str1
//   printf("Test 1: Finding 'o' in \"%s\"\n", str1);
//   printf("strchr: %p\n", strchr(str1, 'o'));
//   printf("ft_strchr: %p\n\n", ft_strchr(str1, 'o'));

//   // Test 2: Find 'z' in str1 (not found)
//   printf("Test 2: Finding 'z' in \"%s\"\n", str1);
//   printf("strchr: %p\n", strchr(str1, 'z'));
//   printf("ft_strchr: %p\n\n", ft_strchr(str1, 'z'));

//   // Test 3: Find '\0' in str1
//   printf("Test 3: Finding '\\0' in \"%s\"\n", str1);
//   printf("strchr: %p\n", strchr(str1, '\0'));
//   printf("ft_strchr: %p\n\n", ft_strchr(str1, '\0'));

//   // Test 4: Find 'T' in str3
//   printf("Test 4: Finding 'T' in \"%s\"\n", str3);
//   printf("strchr: %p\n", strchr(str3, 'T'));
//   printf("ft_strchr: %p\n\n", ft_strchr(str3, 'T'));

//   // Test 5: Find 's' in str3 (multiple occurrences)
//   printf("Test 5: Finding 's' in \"%s\"\n", str3);
//   printf("strchr: %p\n", strchr(str3, 's'));
//   printf("ft_strchr: %p\n\n", ft_strchr(str3, 's'));

//   // Test 6: Find 'a' in str2 (empty string)
//   printf("Test 6: Finding 'a' in \"%s\"\n", str2);
//   printf("strchr: %p\n", strchr(str2, 'a'));
//   printf("ft_strchr: %p\n\n", ft_strchr(str2, 'a'));

//   // Test 7: Find '\0' in str2 (empty string)
//   printf("Test 7: Finding '\\0' in \"%s\"\n", str2);
//   printf("strchr: %p\n", strchr(str2, '\0'));
//   printf("ft_strchr: %p\n\n", ft_strchr(str2, '\0'));

//   return 0;
// }