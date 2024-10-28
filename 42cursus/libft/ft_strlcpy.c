#include "libft.h"

size_t ft_strlcpy(char *dest, const char *src, size_t size)
{
    char *d = dest;
    char *s = (char *)src;
    size_t srclen = ft_strlen(src);
    size_t i;

    i = 0;
    while(i < size-1 && i < srclen)
    {
        *d++ = *s++;
        i++;
    }

    while(i < size)
    {
        *d++ = '\0';
        i++;
    }

    return srclen;
}

// strncpy(char *dest, const char *src, size_t n)
// {
//     size_t i;

//     for (i = 0; i < n && src[i] != '\0'; i++)
//         dest[i] = src[i];
//     for ( ; i < n; i++)
//         dest[i] = '\0';

//     return dest;
// }


// #include <stdio.h>
// #include <string.h>

// size_t
// strlcpy(char * restrict dst, const char * restrict src, size_t maxlen) {
//     const size_t srclen = strlen(src);
//     if (srclen < maxlen) {
//         memcpy(dst, src, srclen+1);
//     } else if (maxlen != 0) {
//         memcpy(dst, src, maxlen-1);
//         dst[maxlen-1] = '\0';
//     }
//     return srclen;
// }

// int main()
// {
//     // dest > size   src < size
//     char string111[7] = "123456";
//     char string121[4] = "abc";
//     strlcpy(string111, string121, 5);
//     printf("%s", string111);
//     printf("%s", "\n");
//     char string112[7] = "123456";
//     char string122[4] = "abc";
//     ft_strlcpy(string112, string122, 5);
//     printf("%s", string112);
//     printf("%s", "\n");
//     char string113[7] = "123456";
//     char string123[4] = "abc";
//     printf("%ld", strlcpy(string113, string123, 5));
//     printf("%s", "\n");
//     char string114[7] = "123456";
//     char string124[4] = "abc";
//     printf("%ld", ft_strlcpy(string114, string124, 5));
//     printf("%s", "\n");

//     // dest > size   src > size
//     char string211[7] = "123456";
//     char string221[4] = "abc";
//     strlcpy(string211, string221, 2);
//     printf("%s", string211);
//     printf("%s", "\n");
//     char string212[7] = "123456";
//     char string222[4] = "abc";
//     ft_strlcpy(string212, string222, 2);
//     printf("%s", string212);
//     printf("%s", "\n");
//     char string213[7] = "123456";
//     char string223[4] = "abc";
//     printf("%ld", strlcpy(string213, string223, 2));
//     printf("%s", "\n");
//     char string214[7] = "123456";
//     char string224[4] = "abc";
//     printf("%ld", ft_strlcpy(string214, string224, 2));
//     printf("%s", "\n");

//     // dest < size   src > size
//     char string311[4] = "123";
//     char string321[7] = "abcdef";
//     strlcpy(string311, string321, 5);
//     printf("%s", string311);
//     printf("%s", "\n");
//     char string312[4] = "123";
//     char string322[7] = "abcdef";
//     ft_strlcpy(string312, string322, 5);
//     printf("%s", string312);
//     printf("%s", "\n");
//     char string313[4] = "123";
//     char string323[7] = "abcdef";
//     printf("%ld", strlcpy(string313, string323, 5));
//     printf("%s", "\n");
//     char string314[4] = "123";
//     char string324[7] = "abcdef";
//     printf("%ld", ft_strlcpy(string314, string324, 5));
//     printf("%s", "\n");


//     // dest > size   src > size
//     char string411[4] = "123";
//     char string421[7] = "abcdef";
//     strlcpy(string411, string421, 2);
//     printf("%s", string411);
//     printf("%s", "\n");
//     char string412[4] = "123";
//     char string422[7] = "abcdef";
//     ft_strlcpy(string412, string422, 2);
//     printf("%s", string412);
//     printf("%s", "\n");
//     char string413[4] = "123";
//     char string423[7] = "abcdef";
//     printf("%ld", strlcpy(string413, string423, 2));
//     printf("%s", "\n");
//     char string414[4] = "123";
//     char string424[7] = "abcdef";
//     printf("%ld", ft_strlcpy(string414, string424, 2));
//     printf("%s", "\n");

// }