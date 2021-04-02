#include <unistd.h>

int 	ft_putchar(char c)
{
	write(1, &c, 1);
	return(0);
}

void 	ft_print_numbers(void)
{
	char i;

	i = 48;
	while(i <= 57)
	{
		ft_putchar(i);
		i++;
	}
}

int 	main(void)
{
	ft_print_numbers();
}