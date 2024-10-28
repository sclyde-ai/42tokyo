char *
strncat(char *s1, const char *s2, size_t n)
{
    unsigned len1 = strlen(s1);
    unsigned len2 = strlen(s2);
    
    if (len2 < n) {
	strcpy(&s1[len1], s2);
    } else {
	strncpy(&s1[len1], s2, n);
	s1[len1 + n] = '\0';
    }
    return s1;
}