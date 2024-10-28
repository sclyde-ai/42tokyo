#include "libft.h"

void* ft_memmove(void *dest, const void *src, size_t size)
{
    unsigned char *d = (unsigned char *)dest;
    unsigned char *s = (unsigned char *)src;
    // size_t dlen = ft_strlen(dest);
    // size_t slen = ft_strlen(src);

    if(d == s) return dest;
    if(dest > src)
    {
        while(*s && size--)
        {
            *d++ = *s++;
        }
    }
    else
    {
        d += size;
        s += size;
        while(size--)
        {
            *d-- = *s--;
        }
    }

    return dest;   
}

// #include <stdio.h>
// #include <string.h>
// #include <stdlib.h>


// // テストケース
// int main() {
//   // テストケース1: 重複なし
//   char str1[] = "abcdefg";
//   char str2[20];
//   my_memmove(str2, str1, strlen(str1) + 1);
//   printf("Test Case 1: %s\n", strcmp(str1, str2) == 0 && memcmp(str1, str2, strlen(str1) + 1) == 0 ? "OK" : "NG");

//   // テストケース2: dest > src (重複あり)
//   char str3[] = "abcdefg";
//   my_memmove(str3 + 2, str3, 5); 
//   printf("Test Case 2: %s\n", strcmp(str3, "ababcefg") == 0 ? "OK" : "NG");

//   // テストケース3: dest < src (重複あり)
//   char str4[] = "abcdefg";
//   my_memmove(str4, str4 + 2, 5);
//   printf("Test Case 3: %s\n", strcmp(str4, "cdefgg") == 0 ? "OK" : "NG");

//   // テストケース4: n = 0
//   char str5[] = "abcdefg";
//   char str6[] = "1234567";
//   my_memmove(str5, str6, 0);
//   printf("Test Case 4: %s\n", strcmp(str5, "abcdefg") == 0 && strcmp(str6, "1234567") == 0 ? "OK" : "NG");

//   // テストケース5: dest == src
//   char str7[] = "abcdefg";
//   my_memmove(str7, str7, strlen(str7) + 1);
//   printf("Test Case 5: %s\n", strcmp(str7, "abcdefg") == 0 ? "OK" : "NG");

//   return 0;
// }