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

int 	ft_strlen(char *str)
{
	int lenght;

	lenght = 0;

	while (*str++)
	{
		lenght++;
	}
	return (lenght);
}

int		ft_count_if(char **tab, int(*f)(char*))
{
	int count;
	int i;

	i = 0;
	count = 0;
	while (tab[i] != 0)
	{
		if ((*f)(tab[i]) == 1)
			count++;
		i++;
	}
	return (count);
}

int 	main(void)
{
	char str1[] = "zebi";
	char str2[] = "l";
	char str3[] = "1";
	char str4[] = "mouche";
	char *str5 = 0;

	char **tab = malloc(sizeof(char *) * 5);
	tab[0] = str1;
	tab[1] = str2;
	tab[2] = str3;
	tab[3] = str4;
	tab[4] = str5;

	ft_putnbr(ft_count_if(tab, &ft_strlen));
}