char *ft_strrchr(const char *s, int c) {
    const char *r;
    *r = NULL;
    while (*s) {
        if (*s == (char)c) r = (char*)s ;
        s++;
    }
    return r;
}