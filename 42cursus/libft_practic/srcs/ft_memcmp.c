int ft_memcmp(const void *buf1, const void *buf2, size_t n) {
    const unsigned char *p1 = buf1;
    const unsigned char *p2 = buf2;
    while (n--) {
        if (*p1 != *p2) return *p1 - *p2;
        p1++;
        p2++;
    }
    return 0;
}