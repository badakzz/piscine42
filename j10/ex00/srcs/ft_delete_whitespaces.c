char	*ft_delete_whitespaces(char *str)
{
	int		i;

	i = 0;
	while (str[i])
	{
		if (str[i] == 32 || str[i] == 9)
			{
				while (str[i])
				{
					str[i] = str[i + 1];
					i++;
				}
				i = 0;
			}
			i++;
	}
	str[i] = '\0';
	return str;
}