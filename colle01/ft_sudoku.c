#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_print_grid(char **grid)
{
	int i;
	int j;

	i = 0;
	while (i < 9)
	{
		j = 0;
		while (j < 9)
		{
			ft_putchar(grid[i][j]);
			if (j < 8)
				ft_putchar(' ');
			j++;
		}
		ft_putchar('\n');
		i++;
	}
}

char	**create_grid(char **argv)
{
	int		i;
	int 	j;
	int 	k;
	char 	**grid;

	i = 0;
	j = 1;
	grid = malloc(sizeof(char *) * 9);
	while (i <= 8 && j <= 9)
	{
		grid[i] = malloc(sizeof(char) * 10);
		k = 0;
		while (k <= 8)
		{
			grid[i][k] = argv[j][k];
			k++;
		}
		grid[i][k] = '\0';
		i++;
		j++;
	}
	return (grid);
}

int 	is_safe(char **grid, int i, int j, char num)
{
	int 	x;
	int 	k;
	int 	l;
	int 	modrow;
	int 	modcol;

	x = 0;
	k = 0;
    while (x <= 8)
    {
        if (grid[i][x] == num)
            return (0);
        x++;
    }
    x = 0;
    while (x <= 8)
    {
        if (grid[x][j] == num)
            return (0);
        x++;
    }
    modrow = i - (i % 3);
	modcol = j - (j % 3);
	while (k < 3)
	{
   	l = 0;
        while (l < 3)
        {
            if (grid[k + modrow][l + modcol] == num)
                return (0);
            l++;
        }
        k++;
   }
   return (1);
}

int		solve(char **grid, int i, int j)
{
	char 	c;

	c = '1';
	if (i == 9)
	{
		return (1);
	}
	if (grid[i][j] >= '1' && grid[i][j] <= '9')
	{
		if (j == 8)
		{
			if (solve(grid, i + 1, 0))
				return (1);
		}
		else
		{
			if (solve(grid, i, j + 1))
				return (1);
		}
		return (0);
	}
	while (c <= '9')
	{
		if (is_safe(grid, i, j, c))
		{
			grid[i][j] = c;
			if (j == 8)
			{
				if (solve(grid, i + 1, 0))
					return (1);
			}
			else
			{
				if (solve(grid, i, j + 1))
					return (1);
			}
			grid[i][j] = '.';
		}
		c++;
	}
	return (0);
}

int	main(int argc, char **argv)
{
	char **grid;
	if (argc <= 10)
	{
		grid = create_grid(argv);
		if (solve(grid, 0, 0) == 1)
			ft_print_grid(grid);
		else
			write(2, "Error", 5);
	}
	else
	{
		write(2, "Error", 5);
	}
	return (0);
}