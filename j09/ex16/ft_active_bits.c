#include "libft.h"

unsigned int 	ft_active_bits(int value)
{
	unsigned int activebits;

	activebits = 0;
	if (value < 0)
		value = -value;
	while (value != 0)
	{
		if ((value % 2) == 1)
			activebits++;
		value = value / 2;
	}
	return activebits;
}

int 	main(void)
{
	ft_putnbr(ft_active_bits(1805));
}