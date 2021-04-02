#include <stdio.h>

unsigned int	ft_collatz_conjecture(unsigned int base)
{
	if (base == 1)
		return (0);
	if (base % 2 == 0)
		base /= 2;
	else
		base = base * 3 + 1;
	return ft_collatz_conjecture(base) + 1;
}

int main ()
{
	printf("%d", ft_collatz_conjecture(15));
}