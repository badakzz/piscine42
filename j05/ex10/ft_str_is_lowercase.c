int 	ft_str_is_lowercase(char *str)
{
	int i;

	i = 0;
	if(str[i] == '\0')
		return (1);
	while (str[i])
	{
		if(str[i] >= 97 && str[i] <= 122)
			i++;
		else
			return (0);
	}
	return (1);
}

int 	main(void)
{
	char str[] = "adwada23asdsa";
	char str2[] = "ASDSADSADASD";
	char str3[] = "dqwdqwdqwdwqd";
	char str4[] = "";
	ft_putnbr(ft_str_is_lowercase(str));
	ft_putnbr(ft_str_is_lowercase(str2));
	ft_putnbr(ft_str_is_lowercase(str3));
	ft_putnbr(ft_str_is_lowercase(str4));
}
