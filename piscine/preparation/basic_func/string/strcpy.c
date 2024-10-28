char *
ft_strcpy(char * restrict dst, const char * restrict src) {
    char *dest = *dst;

    while (*src)
    {
        *dst = *src;
        dst++;
        src++;
    }
    return dest;
}