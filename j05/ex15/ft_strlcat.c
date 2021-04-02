unsigned int	ft_strlcat(char *dest, char *src, unsigned int size)
{
	unsigned int destsize;
	unsigned int i;
	int booleancopy;

	destsize = 0;
	i = 0;
	booleancopy = 0;
	while (dest[destsize])
		destsize++;
	while(src[i])
	{

		if(destsize < (size - 1))
		{
			booleancopy = 1; 
			dest[destsize] = src[i];
		}
		i++;
		destsize++;
	}
	if(booleancopy == 1)
		dest[destsize] = '\0';
	return (destsize);
}

int 	main(void)
{
	unsigned int nb = 2;
	char dest[20] = "pog";
	char src[] = "champion";
	ft_putstr("strlen de dest = ");
	ft_putnbr(strlen(dest));
	ft_putchar('\n');
	ft_putstr("sizeof de dest = ");
	ft_putnbr(sizeof(dest));
	ft_putchar('\n');
	ft_putnbr(ft_strlcat(dest, src, nb));
	ft_putchar('\n');
	ft_putstr("dest = ");
	ft_putstr(dest);
	ft_putchar('\n');
}