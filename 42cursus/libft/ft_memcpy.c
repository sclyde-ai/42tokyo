#include "libft.h"

void* ft_memcpy(void *dest, const void *src, size_t size) 
{
    unsigned char *d = (unsigned char *)dest;
    unsigned char *s = (unsigned char *)src;

    while(*s && size--)
    {
        *d++ = *s++;
    }
    return dest;
}
