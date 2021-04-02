#include <stdio.h>

int 	ft_unmatch(int *tab, int length)
{
	int i;
	int j;
	int k;
	int x;
	int tab2[length];

	k = -1;
	i = 0;
	while (i <= length)
	{
		j = i + 1;
		x = 0;
		while (x <= k && k != -1)
		{
			if (tab2[x] == tab[i])
			{
				i++;
				j = i + 1;
				break;
			}
			else
				x++;
		}
		if (tab[x] != tab[i - 1])
		{
			while (j <= length)
			{
				if (tab[j] == tab[i])
				{
					k++;
					tab2[k] = tab[i];
					i++;
					break;
				}
				else
					j++;
				if (j > length)
					return tab[i];
			}
		}
	}
	return (0);
}

int		main(void)
{
	int tab[9] = {1, 2, 4, 2, 1, 5, 4, 3, 3};
	printf("%d\n", ft_unmatch(tab, 9));
}