int 	ft_strlen(char *str)
{
	int lenght;

	lenght = 0;
	while (*str++)
		lenght++;
	return (lenght);
}