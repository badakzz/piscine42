#include "header.h"

int	errormod(void)
{
	write(1, "Stop : modulo by zero\n", 22);
	return (0);
}