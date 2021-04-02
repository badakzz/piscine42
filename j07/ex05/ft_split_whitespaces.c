#include <stdlib.h>

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
			while(str[i] != 9 && str[i] != 32 && str[i] != 10 && str[i])
			{
				tab[j][k] = str[i];
				k++;
				i++;
			}
			j++;
			if(ft_determine_word_lenght(i, str) != 0)
				tab[j] = (char *)malloc(sizeof(char) * ft_determine_word_lenght(i, str));
			else
				tab[j+1] = NULL;
		}
	}
	return (tab);
}

/*int 	main(void)
{
	int i = 0;
	char str[] = "  hi im   a		new bie  learning malloc\nusage";
	char **ptr = ft_split_whitespaces(str);
	while(ptr[i])
	{
		ft_putstr(ptr[i]);
			i++;
	}
}*/