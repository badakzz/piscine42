int 	ft_iterative_power(int nb, int power)
{
	int i;
	int nbinit;

	i = 0;
	nbinit = nb;

	if(power == 0)
		return (1);
	else
	{
		while (++i < power)
			nb *= nbinit;
		return (nb);
	}
}