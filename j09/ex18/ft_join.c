#include <stdlib.h>
#include <stdio.h>
#include "libft.h"

int		number_of_chars_tab(char **tab)
{
	int i;
	int j;
	int numberofchars;

	i = 0;
	numberofchars = 0;
	while (tab[i])
	{
		j = 0;
		while (tab[i][j])
		{
			numberofchars++;
			j++;
		}
		i++;
	}
	return (numberofchars);
}

int 	number_of_arrays_tab(char **tab)
{
	int i;

	i = 0;
	while (tab[i])
		i++;
	return (i);
}

char 	*ft_join(char **tab, char *sep)
{
	int i;
	int j;
	int k;
	int s;
	char *str;

	str = malloc(sizeof(char) * (number_of_chars_tab(tab) + 1 + ft_strlen(sep)));
	i = 0;
	k = 0;
	while (tab[i])
	{
		j = 0;
		s = 0;
		while (tab[i][j])
		{
			str[k] = tab[i][j];
			j++;
			k++;
		}
		while (sep[s] && i < (number_of_arrays_tab(tab) - 1))
		{
			str[k] = sep[s];
			s++;
			k++;
		}
		i++;
	}
	str[k] = '\0';
	return (str);
}

int		main(void)
{
	char **tab;
	char sep[3] = "|a|";
	tab = malloc(sizeof(char *) * 4);
	tab[0] = "abc";
	tab[1] = "def";
	tab[2] = "gtmlp";
	tab[3] = 0;

	printf("%s", ft_join(tab, sep));
}