#include <unistd.h>
#include <fcntl.h>
#include <errno.h>
#include <string.h>
#include <stdio.h>

extern int errno;

int		main(int argc, char **argv)
{
	int		i;
	int		fd;
	char	buffer;

	if (argc == 1 || argv[1][0] == '-')
	{
		while (read(STDIN_FILENO, &buffer, 1) != 0)
			write(1, &buffer, 1);
	}
	else
	{
		i = 1;
		while (i < argc)
		{
			fd = open(argv[i], O_RDONLY, 0);
			if (fd >= 0)
			{
				while (read(fd, &buffer, sizeof(char)) != 0)
					write(1, &buffer, 1);
			}
			else
			{
				perror("Error");
				return (1);
			}
			i++;
			close(fd);
		}
	}
	return (0);
}