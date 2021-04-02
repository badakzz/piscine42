#include <unistd.h>

int 	ft_putchar(char c)
{
	write (1, &c, 1);
	return (0);
}

void 	ft_putstr(char *str)
{
	int i;

	i = 0;

	while(str[i] != '\0')
	{
		ft_putchar(str[i]);
		i++;
	}
}

int 	main(void)
{
	char *str;

	str = "667";
	ft_putstr(str);
}