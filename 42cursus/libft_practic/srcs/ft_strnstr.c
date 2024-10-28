char *ft_strnstr(const char *haystack, const char *needle, size_t n) {
    
    while(n-- && haystack != '\0')
    {
        if(ft_strncmp(haystack, needle, ft_strlen(needle)) == 0) return (char *)haystack;
        haystack++;
    }
    return NULL;
}