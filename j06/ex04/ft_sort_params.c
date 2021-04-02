#include "libft.h"

int 	main(int argc, char *argv[])
{
	int j;
	int i;
	int k;
	char c;

	i = 1;
	while(i < argc)
	{
		j = 0;
		while(argv[i][j])
		{
			k = j + 1;
			while(argv[i][k])
			{
				if(argv[i][j] > argv[i][k])
				{
					c = argv[i][j];
					argv[i][j] = argv[i][k];
					argv[i][k] = c;
				}
				k++;
			}
			ft_putchar(argv[i][j]);
			j++;
		}
		ft_putchar('\n');
		i++;
	}
	return (0);
}