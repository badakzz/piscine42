void	ft_putnbr(int nb)
{
	int nbinit;
	int size;

	size = 1;

	if (nb < 0)
	{
		ft_putchar('-');
		nb = nb * -1;
	}
	nbinit = nb;
	while(nbinit / 10 > 0)
	{
		nbinit = nbinit / 10;
		size = size * 10;
	}
	nbinit = nb;
	while(size > 0)
	{
		ft_putchar((nbinit / size) + '0');
		nbinit = nbinit % size;
		size = size / 10;
	}
}


int 	main(void)
{
	ft_putnbr(123456);
	ft_putchar(' ');
	ft_putchar('\n');
	ft_putnbr(-654321);
	ft_putchar(' ');
	ft_putchar('\n');
	ft_putnbr(-667);
}