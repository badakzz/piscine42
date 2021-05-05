#include <unistd.h>
#include <fcntl.h>
#include <errno.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

extern int errno;

int		ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

int		ft_atoi(char *str)
{
	int i;
	int number;

	i = 0;
	number = 0;
	while ((str[i] == ' ') || (str[i] == '\t') || (str[i] == '\n')
		|| (str[i] == '\v') || (str[i] == '\f') || (str[i] == '\r'))
		i++;
	if ((str[i] == 45) || (str[i] == 43))
		i++;
	while (str[i] >= 48 && str[i] <= 57)
	{
		number *= 10;
		number += ((int)str[i] - 48);
		i++;
	}
	return (number);
}

int		ft_count_lines(int i, char **argv)
{
	int		fd;
	char 	buffer;
	int		count_lines;

	fd = open(argv[i], O_RDONLY, 0);
	count_lines = 1;
	while (read(fd, &buffer, sizeof(char)))
	{
		if(buffer == '\n' || '\0')
			count_lines++;
	}
	close(fd);
	return count_lines;
}

int		ft_file_size(int i, char **argv)
{
	int 	fd;
	char 	buffer;
	int		size;

	size = 0;
	fd = open(argv[i], O_RDONLY, 0);
	if (fd >= 0)
	{
		while (read(fd, &buffer, sizeof(char)))
			size++;
	}
	close(fd);
	return size;
}

int 	ft_count_chars(int i, char **argv, int count_lines)
{
	int		fd;
	char 	buffer;
	int 	count_chars;

	count_chars = -1;
	fd = open(argv[i], O_RDONLY, 0);
	while (read(fd, &buffer, sizeof(char)))
	{
		if (buffer == '\n')
			count_lines--;
		if (count_lines <= 10)
			count_chars++;
	}
	close(fd);
	return count_chars;
}

int		ft_count_chars_skipped(int i, char **argv, int count_lines)
{
	int		fd;
	char 	buffer;
	int		count_chars;

	count_chars = -1;
	fd = open(argv[i], O_RDONLY, 0);
	while (read(fd, &buffer, sizeof(char)) != 0 && count_lines > 10)
	{
		if (buffer == '\n')
			count_lines--;
		count_chars++;
	}
	close(fd);
	return count_chars;
}

void 	ft_print_name(int i, char **argv)
{
	char 	c;
	int 	j;

	j = 0;
	write(1, "==> ", 4);
	while (argv[i][j])
	{
		c = argv[i][j];
		write(1, &c, 1);
		j++;
	}
	write(1, " <==\n", 5);
}

void	ft_display_last_bytes(int i, char **argv, int offset, int argc)
{
	int 	size;
	char 	buffer;
	int		fd;
	int		bytes_read;
	int 	j;

	j = -1;
	bytes_read = 0;
	fd = open(argv[i], O_RDONLY, 0);
	if (fd >= 0)
	{
		size = ft_file_size(i, argv);
		ft_print_name(i, argv);
		while (bytes_read != (size - offset))
			bytes_read += read(fd, &buffer, 1);
		while (read(fd, &buffer, 1))
			write(1, &buffer, 1);
		if (i != (argc - 1))
			write (1, "\n", 1);
	}
	else
	{
		write(2, "ft_tail: cannot open ", 21);
		while (argv[i][++j])
			write(2, &argv[i][j], 1);
		write(2, " for reading: ", 14);
		perror("");
	}
	close(fd);
}


void 	ft_display_file(int i, char **argv, int argc)
{
	int		count_lines;
	int		count_chars_skipped;
	int		bytes_read;
	int		fd;
	char	buffer;
	int 	j;

	j = -1;
	fd = open(argv[i], O_RDONLY, 0);
	if (fd >= 0)
	{
		ft_print_name(i, argv);
		count_lines = 0;
		bytes_read = 0;
		count_chars_skipped = 0;
		count_lines = ft_count_lines(i, argv);
		count_chars_skipped = ft_count_chars_skipped(i, argv, count_lines);
		while (bytes_read != count_chars_skipped)
			bytes_read += read(fd, &buffer, 1);
		while (read(fd, &buffer, 1))
			write(1, &buffer, 1);
		if (i != (argc - 1))
			write (1, "\n", 1);
	}
	else
	{
		write(2, "ft_tail: cannot open ", 21);
		while (argv[i][++j])
			write(2, &argv[i][j], 1);
		write(2, " for reading: ", 14);
		perror("");
	}
	close(fd);
}

int		main(int argc, char **argv)
{
	int		i;
	int		offset;
	char  	buffer;

	offset = 0;
	if ((argc == 1) || (argv[1][0] == '-' && (ft_strlen(argv[1]) == 1)))
	{
		while (read(STDIN_FILENO, &buffer, 1) != 0)
			write(1, &buffer, 1);
	}
	if (argc >= 2)
	{
		if (argv[1][0] == '-' && argv[1][1] == 'c')
		{
			i = 3;
			offset = ft_atoi(argv[2]);
			while (i < argc)
			{
				ft_display_last_bytes(i, argv, offset, argc);
				i++;
			}
		}
		else
		{
			i = 1;
			while (i < argc)
			{
				ft_display_file(i, argv, argc);
				i++;
			}
		}
	}
	return (0);
}