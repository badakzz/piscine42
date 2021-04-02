#include "libft.h"
#include <stdio.h>
#include <stdlib.h>

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

char 	*ft_itoa(int nb, char *str)
{
	ft_putstr("debut ft_itoa\n");
	ft_putnbr(nb);
	ft_putchar('\n');
	// ft_putstr(str);
	// printf("%p\n", str);

	int i;
	int y;
	int nbinit;
	int neg;
	ft_putstr("lol\n");

	i = 0;
	y = 0;
	nbinit = nb;
	neg = 0;
	if(nb < 0)
	{
		nb = -nb;
		neg = 1;
		str[i] = '-';
		i++;
	}
	while(nb / 10 > 0)
	{
		i++;
		nb = nb / 10;
	}
	if(neg == 1)
		nb = -nbinit;
	else
		nb = nbinit;
	while(nb / 10 > 0)
	{
		ft_putstr("xd0\n");

		y = nb % 10;
		// ft_putstr("xd1\n");
		// ft_putnbr_and_nl(y);
		// ft_putnbr(i);
		// ft_putchar('\n');
		// ft_putstr("nique'\n");
		// ft_putstr(str);
		// ft_putchar('\n');
		// ft_putstr("ta mere\n");
		// ft_putchar(y + '0');
		str[i] = y + '0';
		ft_putstr("str[i] = ");
		ft_putchar(str[i]);
		ft_putchar('\n');
		// ft_putstr("xd2\n");
		// exit(1);
		i--;
		// ft_putstr("xd3\n");
		nb = nb / 10;
		ft_putnbr_and_nl(nb);
		// ft_putstr("xd4\n");
	}
	ft_putstr("xd5\n");

	str[i] = nb + '0';
	ft_putstr("str[i] = ");
		ft_putchar(str[i]);
		ft_putchar('\n');
	ft_putstr("xd5\n");
	ft_putstr(str);

	return (str);
}

int	get_base_length(char *base)
{
	int	base_length;
	int	j;

	base_length = 0;
	while (base[base_length])
	{
		if (base[base_length] == '-' || base[base_length] == '+')
			return (0);
		j = base_length + 1;
		while (base[j])
		{
			if (base[base_length] == base[j])
				return (0);
			++j;
		}
		++base_length;
	}
	if (base_length < 2)
		return (0);
	return (base_length);
}

int	check_errors(char *str, char *base)
{
	int	i;
	int	j;
	int	start;

	start = 0;
	while (str[start] != '\0' && (str[start] == ' ' || str[start] == '\t' ||
		str[start] == '\r' || str[start] == '\n' || str[start] == '\v' ||
		str[start] == '\f'))
		start++;
	i = start;
	while (str[i])
	{
		j = 0;
		while (base[j] && (str[i] != base[j] ||
			(str[i] == '-' || str[i] == '+')))
			++j;
		if (str[i] != base[j] && str[i] != '-' && str[i] != '+')
			return (0);
		i++;
	}
	if (i == 0)
		return (0);
	return (1);
}

int	get_nb(char c, char *base)
{
	int	i;

	i = 0;
	while (base[i] && base[i] != c)
		i++;
	return (i);
}

int	ft_atoi_base(char *str, char *base)
{
	int	s;
	int	i;
	int	res;
	int	negative;
	int	base_length;
	ft_putstr("debut ft_atoi_base\n");

	ft_putstr(str);
	ft_putchar('\n');

	if (!(base_length = get_base_length(base)) || !check_errors(str, base))
		return (0);
	s = 0;
	while (str[s] != '\0' && (str[s] == ' ' || str[s] == '\t' || str[s] == '\r'
		|| str[s] == '\n' || str[s] == '\v' || str[s] == '\f'))
		s++;
	i = s - 1;
	res = 0;
	negative = 1;
	while (str[++i] && (((str[i] == '-' || str[i] == '+') && i == s) ||
		(str[i] != '-' && str[i] != '+')))
	{
		if (str[i] == '-')
			negative = -1;
		else if (str[i] != '+')
			res = (res * base_length) + (get_nb(str[i], base));
	}
	return (res * negative);
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

char 	*ft_itoa_base(char *str, char *base)
{
		ft_putstr("DEBUT ft_itoa_base\n");
	ft_putstr(str);
	ft_putchar('\n');
		ft_putstr(base);
	ft_putchar('\n');
	int	s;
	int	i;
	int	res;
	int	negative;
	int	base_length;

	if (!(base_length = get_base_length(base)) || !check_errors(str, base))
		return (0);
	s = 0;
	while (str[s] != '\0' && (str[s] == ' ' || str[s] == '\t' || str[s] == '\r'
		|| str[s] == '\n' || str[s] == '\v' || str[s] == '\f'))
		s++;
	i = s - 1;
	res = 0;
	negative = 1;
	while (str[++i] && (((str[i] == '-' || str[i] == '+') && i == s) ||
		(str[i] != '-' && str[i] != '+')))
	{
		if (str[i] == '-')
			negative = -1;
		else if (str[i] != '+')
			res = (res * base_length) + (get_nb(str[i], base));
	}

	printf("%p\n", str);
	ft_putchar('\n');
	ft_putnbr(res * negative);
	ft_putchar('\n');
	return (ft_itoa((res * negative), str));
}

int 	ft_count_numbers(int nbr)
{
	int count;

	count = 0;
	while(nbr % 10 > 0)
	{
		count++;
		nbr = nbr / 10;
	}
	return (count);
}

char 	*ft_convert_base(char *nbr, char *base_from, char *base_to)
{
	ft_putstr("ft_convert_base\n");

	char *nbrbase10;
	char *nbrbaseto;
	printf("%p\n", nbr);

	if(base_check(base_from) == 1 && base_check(base_to) == 1 && nbr) 
	{
		ft_putstr("ft_atoi_base de nbr en base 10 = ");
		ft_putnbr(ft_atoi_base(nbr, base_from));
		ft_putchar('\n');
		ft_putstr("count pour nbrbase10 = ");
		ft_putnbr(ft_count_numbers(ft_atoi_base(nbr, base_from)));
		ft_putchar('\n');
		nbrbase10 = (char *)malloc(sizeof(char) * ft_count_numbers(ft_atoi_base(nbr, base_from)));
		ft_putstr("yo\n");
		ft_putnbr(ft_atoi_base(nbr, base_from));
		nbrbase10 = ft_itoa_base(nbr, base_from);
		ft_putstr("nbrbase10 = ");
		ft_putstr(nbrbase10);
		ft_putchar('\n');
		ft_putstr("count pour nbrbase10 = ");
		ft_putnbr(ft_count_numbers(ft_atoi_base(nbrbase10, base_to)));
		ft_putchar('\n');
		nbrbaseto = (char *)malloc(sizeof(char) * ft_count_numbers(ft_atoi_base(nbrbase10, base_to)));
		ft_putstr("yo2\n");
		nbrbaseto = ft_itoa_base(nbrbase10, base_to);
		nbr = nbrbaseto;
		ft_putstr("nbr = ");
		ft_putstr(nbr);
	}
	return (nbr);
}

int		main(void)
{	

	char nbr[4] = "1DF\0";
	/*int nb = 479;
	ft_itoa(nb, nbr);
	ft_putstr(nbr);
	ft_putchar('\n');*/
	char *base = "0123456789ABCDEF";
	char *base2 = "01";
	ft_convert_base(nbr, base, base2);
	return 0;
}