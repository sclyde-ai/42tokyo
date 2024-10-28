#include "libft.h"

char *ft_strnstr(const char *haystack, const char *needle, size_t n)
{
    char *h;
    char *e;
    size_t i;
    size_t nlen;

    h = (char *)haystack;
    e = (char *)needle;
    i = 0;
    nlen = ft_strlen(needle);

    while(i < n && *h)
    {
        if(ft_strncmp(h, e, nlen) != 0)
        {
            return h;
        }
        h++;
    }

    return NULL;
}
