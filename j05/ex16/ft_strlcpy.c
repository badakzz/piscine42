unsigned int	ft_strlcpy(char *dest, char *src, unsigned int size)
{
	unsigned int i;
	unsigned int j;

	i = 0;
	j = 0;

	while(src[j])
		j++;
	while (i < (size - 1) && src[i])
	{
		dest[i] = src[i];
		i++;
	
	}
		dest[i] = '\0';
	return (j);
}

int 	main(void)
{
	char src[] = "pog";
	char dest[] = "champion";
	unsigned int n = 3;

	ft_putnbr(ft_strlcpy(dest, src, n));
	ft_putstr(dest);
	ft_putchar('\n');
	ft_putchar(dest[5]);

}