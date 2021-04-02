char 	*ft_strcapitalize(char *str)
{
	int i;
	int capitalize;

	i = 0;
	capitalize = 1;
	while(str[i])
	{
		if(str[i] >= 97 && str[i] <= 122 && capitalize == 1)
		{
			str[i] -= 32;
			capitalize = 0;
		}
		else
		{
			if(str[i] < 97 || str[i] > 122)
			{
				if(str[i] >= 48 && str[i] <= 57)
					capitalize = 0;
			}
		}
		i++;
	}
	return (str);
}

int 	main(void)
{
	char str[] = "salut, comment tu vas ? 42mots quarante-deux; cinquante+et+un";
	ft_putstr(ft_strcapitalize(str));
}