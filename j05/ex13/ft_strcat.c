char 	*ft_strcat(char *dest, char *src)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while(dest[i])
		i++;
	while(src[j])
	{
		dest[i] = src[j];
		i++;
		j++;
	}
	dest[i] = '\0';
	return dest;
}

int 	main(void)
{
	int i = 0;
	char dest[20] = "pog";
	char src[] = "champ";
	ft_putstr(ft_strcat(dest, src));
}