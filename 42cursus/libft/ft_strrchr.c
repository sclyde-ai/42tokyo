#include "libft.h"

char *ft_strchr(const char *s, int c)
{
    char *p;

    p = (char *)s;
    while(*p)
    {
        if(*p == (char)c) 
            p = (char *)s;
        p++;
    }

    if((char)c == '\0')
        return p;
    else
        return NULL;
}
