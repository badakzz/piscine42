int 	ft_is_prime(int nb)
{
	int div;

	div = 2;

	while(div < nb)
	{
		if (nb % div == 0)
			return 0;
		div++;
	}
	return 1;
}