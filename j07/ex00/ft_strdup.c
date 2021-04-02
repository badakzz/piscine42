char 	*ft_strdup(char *src)
{
	int  i;
	char *dup;

	i = 0;
	while(src[i])
		i++;
	dup = malloc(i);
	i = 0;
	while(src[i])
	{
		dup[i] = src[i];
		i++;
	}
	return (dup);
}