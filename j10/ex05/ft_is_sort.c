#include <unistd.h>

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

int		array_is_sorted(int arg1, int arg2)
{
	if (arg1 > arg2)
		return (-1);
	if (arg1 == arg2)
		return (0);
	return (1);
}

int 	ft_is_sort(int *tab, int length, int(*f)(int, int))
{
	int i;

	i = 0;
	while (i + 1 < length)
	{
		if ((*f)(tab[i], tab[i+1]) == 1 || (*f)(tab[i], tab[i+1]) == 0)
			i++;
		else
			i = length;
	}
	if (i + 1 <= length)
		return (1);
	return (0);
}


int		main(void)
{
	int tab[6] = {1, 2, 2, 5, 6, 2};
	ft_putnbr(ft_is_sort(tab, 6, &array_is_sorted));
	return (0);
}