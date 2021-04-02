#include "libft.h"

int 	ft_max(int *tab, int lenght)
{
	int i;

	i = 1;
	while (i < lenght)
	{
		if (tab[0] < tab[i])
			tab[0] = tab[i];
		i++;
	}
	return tab[0];
}

int		main(void)
{
	int tab[] = {0, 2, 5, 6, 8, 123, 2, 4};
	ft_putnbr(ft_max(tab, 8));
}