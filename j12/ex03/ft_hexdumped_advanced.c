#include <unistd.h>
#include <fcntl.h>
#include <errno.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

int		ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
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
	return (size);
}

char 	*ranged_base10_to_hex(int num,  char *base)
{
	int		i;
	int 	j;
	int		tab[2];
	int 	mod;
	char 	*str;
	char 	temp;


	i = 0;
	j = 0;

	if (num == 0)
	{
		str = malloc(sizeof(char) * 3);
		str[0] = 48;
		str[1] = 48;
		str[2] = '\0';
		return (str);
	}
	else
	{
		while (num > 0)
		{
			mod = num % 16;
			num = num / 16;
			tab[i] = mod;
			i++;
		}
		str = malloc(sizeof(char) * 3);
		while (--i >= 0)
		{
			str[j] = base[tab[i]];
			j++;
		}
		if (ft_strlen(str) != 2)
		{
			temp = str[0];
			str[0] = 48;
			str[1] = temp;
			str[2] = '\0';
		}
	}
	return (str);
}

char 	*char_to_hex(char c, char *base)
{
	int		i;
	int 	j;
	int		tab[2];
	int		int_c;
	int 	mod;
	char 	*str;
	char 	temp;


	i = 0;
	j = 0;
	int_c = (int)c;
	while (int_c > 0)
	{
		mod = int_c % 16;
		int_c = int_c / 16;
		tab[i] = mod;
		i++;
	}
	str = malloc(sizeof(char) * 3);
	while (--i >= 0)
	{
		str[j] = base[tab[i]];
		j++;
	}
	if (ft_strlen(str) != 2)
	{
		temp = str[0];
		str[0] = 48;
		str[1] = temp;
		str[2] = '\0';
	}
	return (str);
}

void	print_offset(int offset)
{
	int 	i;
	int 	j;
	int 	div;
	int 	div_temp;
	int 	mod;
	int 	length;
	int 	div_length;
	int 	bool;
	char 	*hexstr;
	char 	c;

	i = 0;
	j = 0;
	bool = 0;
	div_length = 0;
	if (offset / 256 > 0)
	{
		div = offset / 256;
		div_temp = div;
		mod = offset % 256;
		hexstr = ranged_base10_to_hex(mod, "0123456789abcdef");
		bool = 1;
		div_length = 1;
		while (div / 10 > 0)
		{
			div_length++;
			div = div / 10;
		}
	}
	else
		hexstr = ranged_base10_to_hex(offset, "0123456789abcdef");
	length = ft_strlen(hexstr);
	if (offset == 0)
	{
		while (i <= 4)
		{
			write(1, "0", 1);
			i++;
		}
	}
	if (offset < 10)
	{
		while (i < 7)
		{
			write(1, "0", 1);
			i++;
		}
		c = offset + 48;
		write(1, &c, 1);
	}
	else
	{
		while (i < ((8 - div_length) - length))
		{
			write(1, "0", 1);
			i++;
		}
		if (bool == 1)
			write(1, ranged_base10_to_hex(div_temp, "0123456789abcdef"), div_length);
		while (hexstr[j])
		{
			write(1, &hexstr[j], 1);
			j++;
		}
		if (bool == 1)
		{
			while (i + div_length + length < 8)
			{
				write(1, "0", 1);
				i++;
			}
		}
	}
}

void 	ft_hexdump(int i, int j, char **argv, int bytes_read, int offset, int argc)
{
	// int 	j;
	int 	k;
	int 	x;
	int 	size;
	int 	fd;
	int 	fd_next;
	char 	buffer;
	char 	*str;
	// int 	line;
			// printf("///// i = %d\n", i);

	x = 0;
	str = malloc(sizeof(char) * 16);
	fd = open(argv[i], O_RDONLY, 0);
	size = ft_file_size(i, argv);
	bytes_read = 0;
	while (bytes_read != size)
	{
		if (bytes_read == 0 && i == 1)
		{
			// printf("///// i = %d\n", i);
			print_offset(offset);
			write(1, "  ", 2);
		}
		k = 0;
		while (j < 16 && bytes_read != size)
		{
			bytes_read += read(fd, &buffer, 1);
			write(1, char_to_hex(buffer, "0123456789abcdef"), 2);
			if (buffer == '\n' || buffer == '\t')
				str[j] = '.';
			else
				str[j] = buffer;
			j++;
			if (j != 8 && j != 16)
				write(1, " ", 1);
			if (j == 8)
				write(1, "  ", 2);
			if (j == 16 || bytes_read == size)
			{	
				// line++;
				if (bytes_read == size)
				{
					fd_next = open(argv[i+1], O_RDONLY, 0);
					while (fd_next >= 0 && i <= argc)
					{
						free(str);
						close(fd);
						i++;
						ft_hexdump(i, j, argv, bytes_read, offset, argc);
					}
					if (j >= 8)
						x = 1;
					k = 0;
					while (k < 48 - (j * 3) - x)
					{
						write(1, " ", 1);
						k++;
					}
					k = 0;
				}
				// line++;
				write(1, "  ", 2);
				write(1, "|", 1);
				while (k < j)
				{
					write(1, &str[k], 1);
					k++;
				}
				
					write(1, "|\n", 2);
					offset += j;
					print_offset(offset);
					write(1, "  ", 2);
			}
		}
							j = 0;

	}
}

int		main(int argc, char **argv)
{
	int 	i;
	int 	j;
	int 	fd;

	i = 1;
	j = 0;
	fd = open(argv[i], O_RDONLY, 0);
	if (argc >= 2)
	{	
		if (fd >= 0)
		{
			ft_hexdump(i, 0, argv, 0, 0, argc);
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
	return (0);
}