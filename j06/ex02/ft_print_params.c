#include "libft.h"

int 	main(int argc, char *argv[])
{
	int i;
	int j;

	i = 1;
	while(argv[i] && i < argc)
	{
		j = 0;
		while(argv[i][j])
		{
			ft_putchar(argv[i][j]);
			j++;
		}
		ft_putchar('\n');
		i++;
	}
	return (0);
}