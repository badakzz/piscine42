char 	*ft_strncat(char *dest, char *src, int nb)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while(dest[i])
		i++;
	while(src[j] && j < nb)
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
	int nb = 3;
	char dest[20] = "pog";
	char src[] = "champion";
	ft_putstr(ft_strncat(dest, src, nb));
	}