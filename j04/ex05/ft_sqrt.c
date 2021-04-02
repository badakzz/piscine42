int 	ft_sqrt(int nb)
{
	int multiplier;

	if (nb < 1)
		return 0;
	multiplier = 1;
	while((multiplier * multiplier) < nb)
		multiplier++;
	if ((multiplier * multiplier) == nb)
		return multiplier;
	else
		return 0;
}