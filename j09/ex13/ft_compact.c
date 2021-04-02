#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int		ft_compact(char **tab, int lenght)
{
	int i;
	int j;

	i = 0;
	while (tab[i])
	{
		j = 0;
		while(tab[i][j])
		{
			if (tab[i][j] == '0')
			{
				tab[i][j] = tab[i][j+1];
				lenght--;
			}
			j++;
		}
		i++;
	}
	return (lenght);
}

int 	main(void)
{
	int i = 0;
	int j = 0;
	
	char arrayOfChars[10] = {'1','2','3','5','0','1','2','3','0','\0'};
	char arrayOfChars2[10] = {'1','2','3','5','0','1','2','3','0','\0'};
	char **arrayOfArraysOfChars;
	arrayOfArraysOfChars = (char **)malloc(sizeof(char *) * 2);
	arrayOfArraysOfChars[0] = arrayOfChars;
	arrayOfArraysOfChars[1] = arrayOfChars2;
	ft_compact(arrayOfArraysOfChars, 10);
	while(arrayOfArraysOfChars[i])
	{
		printf("i = %d\n", i);
		j = 0;
		while(arrayOfArraysOfChars[i][j])
		{
			printf("j = %d\n", j);
			printf("%c\n", arrayOfArraysOfChars[i][j]);
			j++;
		}
		i++;
	}
}