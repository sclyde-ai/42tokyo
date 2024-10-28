void	ft_putstr(char *str)
{
	while (*str)
	{
		write(1, str, 1);
		str++;
	}
}

char *ft_strjoin(int size, char **strs, char *sep)
{
    int i;

    i = 0;
    while(str[i])
    {
        ft_putstr(strs[i]);
        ft_putstr(sep);
    }
}