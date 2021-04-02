#include <unistd.h>

char	*ft_to_min(char *str)
{
	int		i;

	i = 0;
	while (str[i])
	{
		if (str[i] <= 90 && str[i] >= 65)
			str[i] = str[i] + 32;
		i++;
	}
	return str;
}

int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i] || s2[i])
	{
		if (s1[i] < s2[i])
			return (-1);
		if (s1[i] > s2[i])
			return (1);
		i++;
	}
	return (0);
}

char	*ft_delete_whitespaces(char *str)
{
	int		i;

	i = 0;
	while (str[i])
	{
		if (str[i] == 32 || str[i] == 9)
			{
				while (str[i])
				{
					str[i] = str[i + 1];
					i++;
				}
				i = 0;
			}
			i++;
	}
	str[i] = '\0';
	return str;
}

int		main(int argc, char **argv)
{
	argc = 1;
	while (argv[argc])
	{
		if (ft_strcmp(ft_to_min(ft_delete_whitespaces(argv[argc])), "bauer") == 0
			|| ft_strcmp(ft_to_min(ft_delete_whitespaces(argv[argc])), "president") == 0
			|| ft_strcmp(ft_to_min(ft_delete_whitespaces(argv[argc])), "attentat") == 0)
			write(1, "Alert!!!\n", 9);
		argc++;
	}
		return 0;
}