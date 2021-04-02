#include "libft.h"

int 	main(int argc, char *argv[])
{
	int j;
	int i;

	i = argc - 1;
	while(i > 0)
	{
		j = 0;
		while(argv[i][j])
		{
			ft_putchar(argv[i][j]);
			j++;
		}
		i--;
		ft_putchar('\n');
	}
	return (0);
}