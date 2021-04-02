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

int 	ft_str_is_alpha(char *str)
{
	int i;

	i = 0;
	if(str[i] == '\0')
		return (1);
	while (str[i])
	{
		if((str[i] >= 65 && str[i] <= 90) || (str[i] >= 97 && str[i] <= 122))
			i++;
		else
			return (0);
	}
	return (1);
}

int 	main(void)
{
	char str[] = "wesh la";
	char str2[] = "weshlamifbienoukoizer";
	char str3[] = "";
	ft_putnbr(ft_str_is_alpha(str));
	ft_putnbr(ft_str_is_alpha(str2));
	ft_putnbr(ft_str_is_alpha(str3));
