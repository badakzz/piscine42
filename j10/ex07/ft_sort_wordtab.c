#include <stdlib.h>
#include <stdio.h>

int 	ft_strlen(char *str)
{
	int length;

	length = 0;

	while (*str++)
	{
		length++;
	}
	return (length);
}

int     ft_determine_words_nbr(char *str)
{
	int i;
	int count;

	i = 0;
	count = 0;
	while(str[i])
	{
		if(str[i] == 9 || str[i] == 32 || str[i] == 10)
			i++;
		else
		{
			while(str[i] != 9 && str[i] != 32 && str[i] != 10 && str[i])
				i++;
			count++;
		}
	}
	return (count);
}

int 	ft_determine_word_lenght(int i, char *str)
{
	int lenght;

	lenght = 0;
	while(str[i])
	{
		if(str[i] == 9 || str[i] == 32 || str[i] == 10)
			i++;
		else
		{
			while(str[i] != 9 && str[i] != 32 && str[i] != 10 && str[i])
			{
				i++;
				lenght++;
			}
			return (lenght);
		}
	}
	return (lenght);
}

char 	**ft_split_whitespaces(char *str)
{
	int 	 i;
	int		 j;
	int      k;
	char **tab;

	i = 0;
	j = 0;
	k = 0;
	tab = (char **)malloc(sizeof(char *) * ft_determine_words_nbr(str) + sizeof(int) * 0);
	*tab = (char *)malloc(sizeof(char) * ft_determine_word_lenght(i, str));
	while(str[i] && i < ft_strlen(str))
	{
		k = 0;
		if(str[i] == 9 || str[i] == 32 || str[i] == 10)
			i++;
		else
		{
			tab[j] = (char *)malloc(sizeof(char) * ft_determine_word_lenght(i, str));

			while(str[i] != 9 && str[i] != 32 && str[i] != 10 && str[i])
			{
				tab[j][k] = str[i];
				k++;
				i++;
			}
			j++;
			tab[j+1] = 0;
		}
	}
	return (tab);
}

int		ft_strcmp(char *s1, char *s2)
{
	while (*s1 != 0 || *s2 != 0)
	{
		if (*s1 != *s2)
			return (*s1 - *s2);
		s1++;
		s2++;
	}
	return (0);
}

void 	ft_swap(char **str, char **str2)
{
	char *temp;

	temp = *str;
	*str = *str2;
	*str2 = temp;
	return;
}

void 	ft_sort_wordtab(char **tab)
{
	int i;
	int j;

	i = 0;
	while (tab[i] && i < 4)
	{
		j = i + 1;
		while (tab[j])
		{
			if (ft_strcmp(tab[i], tab[j]) > 0)
				{
					ft_swap(&tab[i], &tab[j]);
				}
				j++;
		}
		i++;
	}
}

int		main()
{
	static char str[] = "je suis pog mdr lul";

	char **tab = ft_split_whitespaces(str);
	ft_sort_wordtab(tab);
	for (int i = 0; i < 5; i++)
	{
		printf("%s\n", tab[i]);
	}
}