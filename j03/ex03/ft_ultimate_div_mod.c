#include <stdio.h>

void 	ft_ultimate_div_mod(int *a, int *b)
{
	int *c;
	int d;

	d = 0;
	c = &d;
	*c = *a;
	*a = *a / *b;
	*b = *c % *b;
}


int 	main(void)
{
	int *a;
	int *b;
	int c;
	int d;

	c = 6;
	d = 3;
	a = &c;
	b = &d;

	ft_ultimate_div_mod(a, b);
	printf("a = %d \n b = %d", *a, *b);
}