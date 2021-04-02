#include <unistd.h>

void	ft_generic(void)
{
	char *str;

	str = "Tut tut ; Tut tut\n";
	write(1, str, 19);
	return;
}


int 	main(void)
{
	ft_generic();
	return (0);
}