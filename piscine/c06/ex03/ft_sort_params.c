int ft_strcmp(char *s1, char *s2)
{
	while(*s1 == *s2)
	{
		if(*s1 == '\0' || *s2 == '\0')
			return 0;
		s1++;
		s2++;
	}
	return(*s1 - *s2);
}

\
int main(int n, char** a)
{
    int i;
    int j;

    i = 0;
    while(i < n)
    {
        j = i;
        while(j < n)
        {
            if(ft_strcmp(a[i], a[j]) > 0)
                ft_swap(a[i], a[j]);
        }
    }
}