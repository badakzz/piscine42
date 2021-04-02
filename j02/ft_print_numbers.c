#include <unistd.h>

int ft_putchar(char c)
{
	write (1, &c, 1);
	return (0);
}

void ft_print_numbers(void)
{
	int i;

	i = 48;
	while (i <= 57)
	{
		ft_putchar((char)i);
		i = i + 1;
	}
	return;
}