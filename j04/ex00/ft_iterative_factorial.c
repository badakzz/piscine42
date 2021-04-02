#include <unistd.h>

int 	ft_putchar(char c)
{
	write (1, &c, 1);
	return (0);
}


void 	ft_putstr(char *str)
{
	int i;

	i = 0;

	while(str[i] != '\0')
	{
		ft_putchar(str[i]);
		i++;
	}
}

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

int 	ft_iterative_factorial(int nb)
{
	int i;
	int number;
	int permut;

	i = 1;
	number = 0;
	permut = 1;

	if(nb == 0 || nb == 1)
	{
		return (1);
	}

	if(nb > 1)
	{
		while (i <= nb)
		{
			ft_putstr("i debut boucle est egal a");
			ft_putchar(' ');
			ft_putnbr(i);
			ft_putchar('\n');
			number = i * permut;
			ft_putstr("number = i * permut est egal a");
			ft_putchar(' ');
			ft_putnbr(number);
			ft_putchar('\n');
			permut = number;
			ft_putstr("permut est egal a");
			ft_putchar(' ');
			ft_putnbr(permut);
			ft_putchar('\n');
			
			i++;
			ft_putstr("i++ donc i est egal a");
			ft_putchar(' ');
			ft_putnbr(i);
			ft_putchar('\n');
			ft_putchar('\n');
			ft_putchar('\n');
		}
	}
	return (number);
}

int main(void)
{
	int i = 6;
	ft_putnbr(ft_iterative_factorial(i));

}