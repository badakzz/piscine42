#include <unistd.h>
#include <stdlib.h>


void 	ft_putchar(char c)
{
	write (1, &c, 1);
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

int 	ft_nonsense(int nb)
{
	return (nb - 1);
}

int		*ft_map(int *tab, int length, int(*f)(int))
{
	int i;
	int *tabreturns;

	i = 0;
	tabreturns = malloc(sizeof(int) * length);
	while (i < length)
	{
		tabreturns[i] = (*f)(tab[i]);
		i++;
	}
	return (tabreturns);
}

int		main()
{
	int i;
	int tab[6] = {1, 2, 3, 4, 5, 6};
	int *tabreturns = malloc(sizeof(int) * 6);

	tabreturns = ft_map(tab, 6, &ft_nonsense);
	i = 0;

	while (i < 6)
	{
		ft_putnbr(tabreturns[i]);
		i++;
	}
	return (0);
}