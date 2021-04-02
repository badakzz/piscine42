char	*ft_strncpy(char *dest, char *src, unsigned int n)
{
	unsigned int i;

	i = 0;
	while (i < n && src[i])
	{
		dest[i] = src[i];
		i++;
	}
	while (i < n)
	{
		dest[i] = '\0';
		i++;
	}
	return (dest);
}

int 	main(void)
{

	char src[] = "caz";
	int i = 2;
    char dest[30] = "mega demerzer";

  	ft_putstr(ft_strncpy(dest, src, i));

    char dest1[30] = "mega demerzer";

	ft_putchar('\n');
    ft_putstr(strncpy(dest1, src, i));
   
	return (0);
}