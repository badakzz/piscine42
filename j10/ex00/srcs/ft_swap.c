void 	ft_swap(int *a, int *b)
{
	int *swap;
	int intswap;

	intswap = 0;
	swap = &intswap;
	*swap = *a;
	*a = *b;
	*b = *swap;
}