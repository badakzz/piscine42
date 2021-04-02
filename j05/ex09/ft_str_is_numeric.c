int 	ft_str_is_numeric(char *str)
{
	int i;

	i = 0;
	if(str[i] == '\0')
		return (1);
	while (str[i])
	{
		if(str[i] >= 48 && str[i] <= 57)
			i++;
		else
			return (0);
	}
	return (1);
}

int 	main(void)
{
	char str[] = "412421421 124";
	char str2[] = "42141221421";
	char str3[] = "";
	ft_putnbr(ft_str_is_numeric(str));
	ft_putnbr(ft_str_is_numeric(str2));
	ft_putnbr(ft_str_is_numeric(str3));
}
