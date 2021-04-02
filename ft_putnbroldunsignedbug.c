void ft_putnbr(int nb)
{
	int i;
	int j;
	int y;
	int nbinit;
	char tab[11];

	i = 1;
	j = 0;
	y = 0;
	nbinit = nb;

	while(nb / 10 > 0)
	{
		i++;
		nb = nb / 10;
	}

	j = i;
	nb = nbinit;

	while(i > 0)
	{
		y = nb % 10;
		tab[i] = y + '0';
		printf("tabizer est egal a %d \n", tab[i]);
		i--;
		nb = nb / 10;
		printf("nb2ze rest egal a %d \n", nb);
	}

	i = 0;
	
	while(i <= j)
	{
		ft_putchar(tab[i]);
		i++;
	}
}