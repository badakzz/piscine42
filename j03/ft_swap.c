/*#include <stdio.h>

void ft_swap(int *a, int *b)
{
	int *swap;

	swap = 0;

	printf("a = %d", *a);
	printf("b = %d", *b);

	*swap = *a;

	*a = *b;
	*b = *swap;

	printf("a = %d", *a);
	printf("b = %d", *b);

}

int main(void)
{
	int *a;
	int *b;

	a = 0;
	b = 0;

	*a = 2;
	*b = 3;

	ft_swap(a, b);
}*/

#include <stdio.h>

void ft_swap(int *a, int *b)
{
	int *swap;
	int intswap;

	intswap = 0;

	swap = &intswap;

	printf("a = %d", *a);
	printf("b = %d", *b);

	*swap = *a;

	*a = *b;
	*b = *swap;

	printf("a = %d", *a);
	printf("b = %d", *b);

}

int main(void)
{
	int *a;
	int *b;
	int c;
	int d;

	c = 2;
	d = 3;

	a = &c;
	b = &d;

	ft_swap(a, b);
}