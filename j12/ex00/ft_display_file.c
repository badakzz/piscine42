#include <unistd.h>
#include <fcntl.h>

int		main(int argc, char **argv)
{
	int		fd;
	char	buffer;

	fd = open(argv[1], O_RDONLY, 0);
	if (argc != 2)
	{
		if (argc < 2)
			write(2, "File name missing.\n", 19);
		if (argc > 2)
			write(2, "Too many arguments.\n", 19);
		return (1);
	}
	while (read(fd, &buffer, sizeof(char)) != 0) 
	{
		write(1, &buffer, 1);
	}
	close(fd);
	return (0);
}