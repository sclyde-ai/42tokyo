void *ft_memchr(const void *buf, int c, size_t n) {
    const unsigned char *p = buf;
    const unsigned char u = (unsigned char)c;

    while (n--) {
        if (*p == c) return (void *)p;
        p++;
    }
    return NULL;
}