#include "libft.h"

size_t ft_strncmp(const char *s1, const char *s2, size_t n)
{
    char *p1;
    char *p2;

    p1 = (char *)s1;
    p2 = (char *)s2;

    while((*p1 || *p2) && n--)
    {
        if(*p1 != *p2)
        {
            return *p2 - *p1;
        }
    }
    return 0;
}
