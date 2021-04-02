#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int 	ft_putchar(char c)
{
	write (1, &c, 1);
	return (0);
}

int 	ft_strlen(char *str)
{
	int lenght;

	lenght = 0;
	while (*str++)
	{
		lenght++;
	}
	return (lenght);
}

char 	*ft_strrev(char *str)
{
	int i;
	int j;
	char c;

	i = 0;
	j = ft_strlen(str) - 1;
	c = ' ';

	while (j > i)
	{
		printf("j = %d \n", j);
		printf("i = %d \n", i);
		ft_putchar(str[j]);
		c = str[i];
		str[i] = str[j];
		printf("str1 : %s", str);
		str[j] = c;
		printf("\n");
		j--;
		i++;
	}
	/*while (str[j--])  notation pog, j-- a la fin de la boucle. (str[--j]) j-- au debut de la boucle  */
	return str;
}


int main(void)
{
	char str[] = "cacazer";
	// racazec recazac rezacac recazac 
	ft_strrev(str);
	printf("%s", str);
}