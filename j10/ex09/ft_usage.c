#include "header.h"

int		ft_usage(int a, int b)
{
	write(1, "error : only [ - + * / % ] are accepted.\n", 41);
	return (a + b);
}