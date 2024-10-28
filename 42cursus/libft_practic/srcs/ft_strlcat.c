size_t my_strlcat(char *dest, const char *src, size_t size) {
    size_t dest_len = my_strlen(dest);
    size_t src_len = my_strlen(src);

    if (dest_len < size - 1 && size > 0) {
        size_t copy_len = ((size - dest_len - 1) > src_len) ? src_len : (size - dest_len - 1);
        ft_memcpy(dest + dest_len, src, copy_len);
        dest[dest_len + copy_len] = '\0';
    }
    return dest_len + src_len;
}