int 	ft_str_is_uppercase(char *str)
{
	int i;

	i = 0;
	if(str[i] == '\0')
		return (1);
	while (str[i])
	{
		if(str[i] >= 65 && str[i] <= 90)
			i++;
		else
			return (0);
	}
	return (1);
}

int 	main(void)
{

	char str[] = "pogChamp";
	char str2[] = "POG123";
	char str3[] = "POGCHAMP";
	char str4[] = "";

	ft_putnbr(ft_str_is_uppercase(str));
	ft_putnbr(ft_str_is_uppercase(str2));
	ft_putnbr(ft_str_is_uppercase(str3));
	ft_putnbr(ft_str_is_uppercase(str4));
}
