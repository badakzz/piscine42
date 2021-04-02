#include <unistd.h>

int 	base_check(char *base)
{
	int i;
	int j;
	int base_lenght;

	i = 0;
	base_lenght = 0;

	while(base[base_lenght])
	{	
		if(base[base_lenght] < 48 || (base[base_lenght] > 59 && base[base_lenght] < 65) || (base[base_lenght] > 90 && base[base_lenght] < 97) || base[base_lenght] > 122)
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

void 	ft_putnbr_base(int nbr, char* base)
{
	int base_lenght;
	int i;
	int nbr_mod[100];

	base_lenght = 0;
	i = 0;
	if(base_check(base) == 1)
	{
		while(base[base_lenght])
			base_lenght++;
		if(nbr < 0)
		{
			ft_putchar('-');
			nbr *= -1;
		}
		while(nbr)
		{
			nbr_mod[i] = nbr % base_lenght;
			nbr = nbr / base_lenght;
			i++;
		}
		while(--i >= 0)
			ft_putchar(base[nbr_mod[i]]);
	}
}

int main(void)
{
	int nbr = 12;
	char base[] = "0123456789ABCDEF";
	ft_putnbr_base(nbr, base);
}