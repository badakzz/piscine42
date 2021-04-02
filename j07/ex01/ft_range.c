#include <stdlib.h>

int     *ft_range(int min, int max)
{
    int  i;
    int  *tab;

    i = 0;
    if(min >= max)
    	return (0);
    tab = (int *)malloc(sizeof(int) * (max - min));
    while(min < max)
    {
    	tab[i] += min;
        i++;
        min++;
    }
    return (tab);
}