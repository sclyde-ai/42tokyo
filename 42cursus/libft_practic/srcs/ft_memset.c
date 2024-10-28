void memset(void *buf, int c, size_t n)
{
    unsigned char *p = (unsigned char *)buf;
    const unsigned char t = (unsigned char)c;
    
    while(n--) *p++ = t;
    return buf;
}
