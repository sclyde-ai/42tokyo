#include "libft.h"

size_t ft_strlcat(char *dest, const char *src, size_t size) {
    size_t destlen = ft_strlen(dest);
    size_t srclen = ft_strlen(src);
    char *d = dest;
    char *s = (char *)src;
    size_t i;

    if(destlen > size){
        return size;
    }
    else{
        while(*d)
        {
            d++;
        }
        i = 0;
        while(i < size - destlen - 1 && i < srclen)
        {
            *d++ = *s++;
            i++;
        }
        *d = '\0';
    }
    return destlen + i;
}

// #include <stdio.h>
// #include <string.h>

// size_t
// strlcat(char * restrict dst, const char * restrict src, size_t maxlen) {
//     const size_t srclen = strlen(src);
//     const size_t dstlen = strnlen(dst, maxlen);
//     if (dstlen == maxlen) return maxlen+srclen;
//     if (srclen < maxlen-dstlen) {
//         memcpy(dst+dstlen, src, srclen+1);
//     } else {
//         memcpy(dst+dstlen, src, maxlen-dstlen-1);
//         dst[maxlen-1] = '\0';
//     }
//     return dstlen + srclen;
// }

// int main()
// {
//     // dest > size   src < size
//     char string111[7] = "123456";
//     char string121[4] = "abc";
//     ft_strlcat(string111, string121, 5);
//     printf("%s", string111);
//     printf("%s", "\n");
//     char string112[7] = "123456";
//     char string122[4] = "abc";
//     ft_strlcat(string112, string122, 5);
//     printf("%s", string112);
//     printf("%s", "\n");
//     char string113[7] = "123456";
//     char string123[4] = "abc";
//     printf("%ld", ft_strlcat(string113, string123, 5));
//     printf("%s", "\n");
//     char string114[7] = "123456";
//     char string124[4] = "abc";
//     printf("%ld", ft_strlcat(string114, string124, 5));
//     printf("%s", "\n");

//     // dest > size   src > size
//     char string211[7] = "123456";
//     char string221[4] = "abc";
//     ft_strlcat(string211, string221, 2);
//     printf("%s", string211);
//     printf("%s", "\n");
//     char string212[7] = "123456";
//     char string222[4] = "abc";
//     ft_strlcat(string212, string222, 2);
//     printf("%s", string212);
//     printf("%s", "\n");
//     char string213[7] = "123456";
//     char string223[4] = "abc";
//     printf("%ld", ft_strlcat(string213, string223, 2));
//     printf("%s", "\n");
//     char string214[7] = "123456";
//     char string224[4] = "abc";
//     printf("%ld", ft_strlcat(string214, string224, 2));
//     printf("%s", "\n");

//     // dest < size   src > size
//     char string311[4] = "123";
//     char string321[7] = "abcdef";
//     ft_strlcat(string311, string321, 5);
//     printf("%s", string311);
//     printf("%s", "\n");
//     char string312[4] = "123";
//     char string322[7] = "abcdef";
//     ft_strlcat(string312, string322, 5);
//     printf("%s", string312);
//     printf("%s", "\n");
//     char string313[4] = "123";
//     char string323[7] = "abcdef";
//     printf("%ld", ft_strlcat(string313, string323, 5));
//     printf("%s", "\n");
//     char string314[4] = "123";
//     char string324[7] = "abcdef";
//     printf("%ld", ft_strlcat(string314, string324, 5));
//     printf("%s", "\n");


//     // dest > size   src > size
//     char string411[4] = "123";
//     char string421[7] = "abcdef";
//     ft_strlcat(string411, string421, 2);
//     printf("%s", string411);
//     printf("%s", "\n");
//     char string412[4] = "123";
//     char string422[7] = "abcdef";
//     ft_strlcat(string412, string422, 2);
//     printf("%s", string412);
//     printf("%s", "\n");
//     char string413[4] = "123";
//     char string423[7] = "abcdef";
//     printf("%ld", ft_strlcat(string413, string423, 2));
//     printf("%s", "\n");
//     char string414[4] = "123";
//     char string424[7] = "abcdef";
//     printf("%ld", ft_strlcat(string414, string424, 2));
//     printf("%s", "\n");
// }
