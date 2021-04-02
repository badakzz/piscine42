#include "libft.h"

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

int 	base_check(char *base)
{
	int i;
	int j;
	int base_lenght;

	i = 0;
	base_lenght = 0;

	while(base[base_lenght])
	{	
		if(base[base_lenght] < 48 || (base[base_lenght] > 59 && base[base_lenght] < 65)
			|| (base[base_lenght] > 90 && base[base_lenght] < 97)
			|| base[base_lenght] > 122)
			return (0);
		base_lenght++;
	}
	if(base_lenght <= 1)
		return (0);
	while(i <= base_lenght)
	{
		j = i + 1;
		while(j < base_lenght)
		{	
			if(base[i] == base[j])
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int 	ft_atoi_base(char *str, char *base)
{
	int i;
	int j;
	int nbr;
	int neg;
	int base_lenght;
	int pow;
	int puissance;

	i = 0;
	nbr = 0;
	base_lenght = 0;
	pow = 0;
	if(str[i] == 45)
	{
		neg = 1;
		i++;
	}
	if(base_check(base) == 1)
	{
		while(base[base_lenght])
			base_lenght++;
		while(str[i])
			i++;
		i--;
		while(i >= 0)
		{
			j = 0;
			while(j <= base_lenght)
			{
				if(base[j] == str[i])
				{
					puissance = ft_iterative_power(base_lenght, pow);
					nbr += j * puissance;
					pow++;
				}
				j++;
			}
			i--;
		}
	}
	if(neg == 1)
		return (-nbr);
	else
		return (nbr);
}

int 	main(void)
{
	char str[] = "1DF";
	char base[] = "0123456789ABCDEF";
	ft_putnbr(ft_atoi_base(str, base));
}