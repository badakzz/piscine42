#include <stdio.h>

char 	rotate_min(char c)
{
	c = ((c - 97 + 42) % 26) + 97;
	return (c);
}

char rotate_maj(char c)
{
	c = ((c - 65 + 42) % 26) + 65;
	return c;
}

char	*ft_rot42(char *str)
{
	int i;

	i = 0;
	while (str[i])
	{
		if(str[i] <= 'Z' && str[i] >= 'A')
			str[i] = rotate_maj(str[i]);
		if(str[i] <= 'z' && str[i] >= 'a')
				str[i] = rotate_min(str[i]);
		i++;
	}
	return str;
}

int	main()
{
	char	tab[] = "Ss";
	printf("%s", ft_rot42(tab));
	return 0;
}