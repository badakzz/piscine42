int 	ft_find_next_prime(int nb)
{
	int div;

	div = 2;
	nb += 1;
	while(div < nb)
	{
		if(nb % div == 0 && nb != div)
		{
			nb++;
			div = 1;
		}
		div ++;
	}
	return nb;
}