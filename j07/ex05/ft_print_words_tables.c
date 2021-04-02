#include "ft_split_whitespaces.c"
#include <unistd.h>

void 	ft_putchar(char c)
{
	write (1, &c, 1);
}

void 	ft_print_words_tables(char **tab)
{
	int i;
	int j;

	i = 0;
	while(tab[i])
	{
		j = 0;
		while(tab[i][j])
		{
			ft_putchar(tab[i][j]);
			j++;
		}
		ft_putchar('\n');
		i++;
	}
}

int 	main(void)
{
	char str[] = "  hi im   a		new bie  learning malloc\nusage";
	char **ptr = ft_split_whitespaces(str);

	ft_print_words_tables(ptr);
	return (0);
}