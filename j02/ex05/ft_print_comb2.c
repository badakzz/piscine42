#include <unistd.h>

int		ft_putchar(char c)
{
	write (1, &c, 1);
	return (0);
}

void    ft_writearraycomb(int *tab)
{
    ft_putchar(tab[0] + '0');
    ft_putchar(tab[1] + '0');
    ft_putchar(' ');
    ft_putchar(tab[2] + '0');
    ft_putchar(tab[3] + '0');
}

void    ft_print_comb2(void)
{
    int numbers[4] = {-1, -1, -1, -1};

    while(++numbers[0] < 10)
    {
        while(++numbers[1] < 10)
        {
            while(++numbers[2] < 10)
            {            
                while(++numbers[3] < 10)
                    {
                        if(numbers[3] > numbers[1] && numbers[2] >= numbers[0])
                            if(numbers[0] == 9 && numbers[1] == 8 && numbers[3] == 9)
                                    ft_writearraycomb(numbers);
                                else
                                {
                                    ft_writearraycomb(numbers);
                                    ft_putchar(',');
                                }
                    }
                numbers[3] = 0;
            }
            numbers[2] = 0;
        }
        numbers[1] = 0;
    }
}

int		main(void)
{
	ft_print_comb2();
}