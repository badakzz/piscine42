#include "header.h"

int	errordiv(void)
{
	write(1, "Stop : division by zero\n", 24);
	return (0);
}