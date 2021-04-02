char 	*ft_strlowcase(char *str)
{
	int i;

	i = 0;
	while(str[i])
	{
		if(str[i] >= 65 && str[i] <= 90)
		str[i] += 32;
		i++;
	}
	return (str);
}

int 	main(void)
{
	char str[] = "POG pOg 123 PoG ; dwqQ";
	ft_putstr(ft_strlowcase(str));
}