int 	ft_atoi(char *str)
{
 	int i;
	int n;
	int neg;

	i = 0;
	n = 0;
	neg = 0;
	if (str[i] == 45)
	{
		neg = 1;
		i++;
	}
	while (str[i])
	{
		n = n * 10;
		n = n + (str[i] - '0');
		i++;	
	}
	if (neg == 1)
		return (-n);
	else
		return (n);
}

int 	main(void)
{
	char *str = "-667";
	ft_putnbr(ft_atoi(str));
}