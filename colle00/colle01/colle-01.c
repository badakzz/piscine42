void 	printcase1(int x)
{
	int j;

	j = 1;
	while (j <= x)
	{
		if(j == 1)
		{
			ft_putchar('/');
			if(j == x)
				ft_putchar('\n');
		}
		if(j > 1 && j < x)
			ft_putchar('*');
		if(j == x && j != 1)
		{
			ft_putchar(92);
			ft_putchar('\n');
		}
		j++;
	}
}

void 	printcase2(int x)
{
	int j;

	j = 1;
	while (j <= x)
	{
		if(j == 1 && j != x)
			ft_putchar('*');
		if(j > 1 && j < x)
			ft_putchar(' ');
		if(j == x)
		{
			ft_putchar('*');
			ft_putchar('\n');
		}
		j++;
	}
}

void 	printcase3(int x)
{
	int j;

	j = 1;
	while (j <= x)
	{
		if(j == 1)
		{
			ft_putchar(92);
			if(j == x)
				ft_putchar('\n');
		}
		if(j > 1 && j < x)
			ft_putchar('*');
		if(j == x && j != 1)
		{
			ft_putchar('/');
			ft_putchar('\n');
		}
		j++;
	}
}

void 	colle(int x, int y)
{
	int i;

	i = 1;
	while (i <= y)
	{
		if(i == 1)
			printcase1(x);
		if(i > 1 && i < y)
			printcase2(x);
		if(i == y && i != 1)
			printcase3(x);
		i++;
	}
}