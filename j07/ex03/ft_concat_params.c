int 	ft_charsinargv(int argc, char **argv)
{
	int i;
	int j;
	int count;

	i = 1;
	count = 0;
	while(i < argc)
	{
		j = 0;
		while(argv[i][j])
		{
			count++;
			j++;
		}
		i++;
	}
	return (count);
}

char 	*ft_concat_params(int argc, char **argv)
{
	int  i;
	int  k;
	int	 j;
	char *str;

	i = 1;
	k = 0;
	str = (char *)malloc(sizeof(char) * ft_charsinargv(argc, argv));
	while(i < argc)
	{
		j = 0;
		while(argv[i][j])
		{
			str[k] = argv[i][j];
			k++;
			j++;
		}
		i++;
		if(i != argc)
		{
			str[k] = '\n';
			k++;
		}
	}
	return (str);
}