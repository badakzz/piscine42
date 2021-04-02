#include <unistd.h>
#include <stdio.h>


int ft_strlen(char *str)
{
	int i;
	int lenght;

	i = 0;
	lenght = 0;

	while (str[i] != '\0')
	{
		lenght = lenght + 1;
		i++;
	}
	return (lenght);
}


int ft_atoi(char *str)
{
	int i;
	int n;
	int m;
	int strsize;
	int tab[ft_strlen(str)];
	int total;

	i = -1;
	n = 0;
	m = 1;
	strsize = ft_strlen(str);
	total = 0;


	while(i < (strsize - 1))
	{
		i++;
		tab[i] = str[i] - '0';
	}

	while(i > -1)
	{
		i--;
		n = tab[i];
		tab[i]= m * 10 * tab[i];
		m = tab[i] / n;
	}

	i = 0;

	while(i < strsize)
	{
		total = total + tab[i];
		i++;
	}

	return (total);
}

/*char *str*/ int ft_itoa(int nb)
{
	int i;
	int x;
	//int tab[3];
	double y;
	//double z;
	double z;
	//int total;

	i = 0;
	x = 0;
	y = 0;
	z = 0;

	printf("nb est egal a %d \n", nb);

	while(nb / 10 > 1)
	{
		x = nb / 10;
		printf("x est egal a %d \n", x);
		y = (double)nb / 10;
		printf("y est egal a %f \n", y);
		// w = (y - x) * 10;
		printf("w est egal a %f \n cad %f - %d", z, y, x);
		z = (y - x) * 10;
		printf("z est egal a %f \n", z);

		// tab[i] = z;
		i++;
		nb = nb / 10;
		printf("nb est egal a %d \n", nb);
	}
//	tab[i] = nb;
/*
	i = 0;
	while(i <= 3)
	{
		printf("%d \n", tab[i]);
		i++;
	}*/
	return (0);
}

/*void ft_putnbr(int nb)
{
	write (1, &c, 1);
	return (0);
}*/

int main(void)
{

	//int c = 667;

ft_itoa(667)/*)*/;


}