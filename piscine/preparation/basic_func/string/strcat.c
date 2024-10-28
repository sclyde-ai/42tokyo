char *ft_strcat(s, append)
{
	char *save = s;

	// for (; *s; ++s);
	while(*s == '\0')
	{
		s++;
	}
	s--;
	// while (*s++ = *append++);
	while(*append == '\0')
	{
		*s = *append;
		s++;
		append++;
	}
	return(save);
}