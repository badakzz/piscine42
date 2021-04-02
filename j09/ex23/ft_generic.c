#include <unistd.h>

void		ft_generic(void)
{
	char str[19] = "Tut tut ; Tut tut\n"
	write(1, str, 19);
	return;
}