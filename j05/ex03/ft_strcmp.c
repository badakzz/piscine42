#include <stdio.h>
#include <unistd.h>
#include <string.h>

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

int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i] && s2[i] && s1[i] == s2[i])
		i++;
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}

/*int		ft_strcmp(char *s1, char *s2)
{
	int sums1;
	int sums2;
	int i

	i = 0;
	sums1 = 0;
	sums2 = 0;
	while(s1[i])
	{
		sums1 += s1[i];
		i++;
	}
	i = 0;
	while(s2[i])
	{
		sums2 += s2[i];
		i++;		
	}
	if(sums1 == sums2)
		return (0);
	return (sums1 - sums2);
}*/

int 	main(void)
{
	char s1[] = "qqzqqqq";
	char s2[] = "qqqqqqqqqqqq";
	ft_putnbr(strcmp(s1, s2));
	ft_putchar('\n');
	ft_putnbr(ft_strcmp(s1, s2));
}