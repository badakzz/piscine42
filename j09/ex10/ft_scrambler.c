#include <stdio.h>
#include <stdlib.h>

void	ft_scrambler(int ***a, int *b, int *******c, int ****d)
{
	int 	temp_b;
	int 	temp_c;
	int 	temp_d;

	temp_c = *******c;
	*******c = ***a;
	temp_d = ****d;
	****d = temp_c;
	temp_b = *b;
	*b = temp_d;
	***a = temp_b;
	return;
}

int		main(void)
{
	int ***a;
	a = malloc(1000);
	*a = malloc(1000);
	**a = malloc(1000);
	***a = 2;
	int *b;
	b = malloc(1000);
	*b = 3;
	int *******c;
	c = malloc(1000);
	*c = malloc(1000);
	**c = malloc(1000);
	***c = malloc(1000);
	****c = malloc(1000);
	*****c = malloc(1000);
	******c = malloc(1000);
	*******c = 4;
	int ****d;
	d = malloc(1000);
	*d = malloc(1000);
	**d = malloc(1000);
	***d = malloc(1000);
	****d = 5;

	ft_scrambler(a, b, c, d);
	printf("%d\n", ***a);
	printf("%d\n", *b);
	printf("%d\n", *******c);
	printf("%d\n", ****d);
}