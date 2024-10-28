#include "libft.h"

void *memset(void *s, int c, size_t size)
{
    unsigned char *p = (unsigned char *)s;

    while(size--)
    {
        *p = (unsigned char)c;
        p++;
    }
    return s;
}