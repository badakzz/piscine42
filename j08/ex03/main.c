#include "ft_point.h"
#include <stdio.h>

void	set_point(t_point *point)
{
	point->x = 42;
	printf("%d", point->x); 
	point->y = 21;
}
int 	main(void)
{
	t_point point;
	set_point(&point);
	return (0);
}