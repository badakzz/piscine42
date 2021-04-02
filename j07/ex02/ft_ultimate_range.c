int     ft_ultimate_range(int **range, int min, int max)
{
    int  i;
    int  *tab;

    i = 0;
    if(min >= max)
        range = NULL;
    else
    {
        tab = (int *)malloc(sizeof(int) * (max - min));
        while(min < max)
        {
           tab[i] += min;
           i++;
           min++;
       }
        *range = tab;
   }   
   return (i);
}