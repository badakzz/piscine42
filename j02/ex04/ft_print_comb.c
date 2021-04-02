#include <unistd.h>

int 	ft_putchar(char c)
{
	write (1, &c, 1);
	return (0);
}

void 	ft_putcharofarray(int *tab)
{
	ft_putchar(tab[0] + '0');
	ft_putchar(tab[1] + '0');
	ft_putchar(tab[2] + '0');
}

void 	ft_print_comb(void)
{
	int numbers[3] = {-1, -1, -1};

	while(++numbers[0] < 10)
		{
			numbers[1] = 0;
			while(++numbers[1] < 10)
			{
				numbers[2] = 0;
				while(++numbers[2] < 10)
				{
					if(numbers[0] < numbers[1] && numbers[1] < numbers[2])
						if(100 * numbers[0] + 10 * numbers[1] + numbers[2] != 789)
						{
							ft_putcharofarray(numbers);
							ft_putchar(',');
							ft_putchar(' ');
						}
						else
						{
							ft_putcharofarray(numbers);
						}
				}
			}
		}
}
int main(void)
{
	ft_print_comb();
}