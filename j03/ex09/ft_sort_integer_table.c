#include <unistd.h>
#include <stdio.h>


int 	ft_putchar(char c)
{
	write (1, &c, 1);
	return (0);
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

void 	ft_sort_integer_table(int *tab, int size)
{
	int i;
	int j;
	int permut;

	i = 0;
	while (i < size)
	{
		j = i + 1;
		while (j < size)
		{
			if (tab[i] > tab[j])
			{
				permut = tab[i];
				tab[i] = tab[j];
				tab[j] = permut;
			}
			j++;
		}
		i++;
	}
}

int 	main(void)
{
	int i = 0;
	int tab[5] = {3, 7, 8, 10, 1};
	ft_sort_integer_table(tab, 5);
	while(i < 5)
		{
			ft_putnbr(tab[i]);
			ft_putchar('\n');
			//printf("tab i = %d \n", tab[i]);
			i++;
		}
}