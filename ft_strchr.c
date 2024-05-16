char	*ft_strchr(const char *s, int c)
{
	while (*s)
		if (*s++ == c)
			break ;
	return (s);
}
