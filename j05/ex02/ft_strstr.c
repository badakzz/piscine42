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

char	*ft_strstr(char *str, char *to_find)
{
	int i;
	int j;
	int bool;
	int size;

	i = 0;
	j = 0;
	bool = 0;
	size = 0;

while (to_find[size])
		size++;
	if (size == 0)
		return (str);
	while(str[i])
	{
		ft_putstr("loop");
		ft_putchar('\n');
		ft_putchar(str[i]);
		ft_putchar('\n');
		if(str[i] == to_find[0])
		{
			ft_putstr("if");
			ft_putchar(str[i]);
			ft_putchar('\n');

			bool = 1;
			j = i;
			i = 0;
			break;
		}
		i++;
	}
	i = 0;
	while(str[j])    // pas str[i] car on le remplace, il n existe plus. tant que cest une moto, on fait des tours, mais ma moto devient une voiture. on a transforme les motos en voiture donc on ne peut plus regarder les motos, il faut regarder les voitures
	{
		str[i] = str[j];
		ft_putchar(str[i]);
		ft_putchar('\n');
		j++;
		i++;
	}
	str[i] = '\0';
	if(bool == 0)
		return (0);
	return (str);

}

int main(void)
{
	char haystack[] = "botte de foinzer";
	char needle[] = "de";
	// ft_putstr(strstr(haystack, neeedle));
	ft_putstr(ft_strstr(haystack, needle));
}