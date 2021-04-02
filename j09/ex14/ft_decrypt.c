#include "ft_perso.h"
#include <stdlib.h>
#include "libft.h"

int 	numberofstructs(char *str)
{
	int 		i;
	int 		length;

	i = 0;
	length = 0;
	while (str[i])
	{
		if (str[i] == ';')
			length += 1;
		i++;
	}
	return (length);
}

int 	get_data_length(char *str, int i)
{
	int 		length;

	length = 0;
	while (str[i] != '|' && str[i] != ';' && str[i] != '\0')
	{
		length++;
		i++;
	}
	return (length);
}

char 	*get_data(char *str, int i)
{
	int j;
	char	*str2;

	j = 0;
	str2 = (char *)malloc(sizeof(char) * get_data_length(str, i));
	while (str[i] != '|' && str[i] != ';' && str[i] != '\0')
	{	
		str2[j] = str[i];
		i++;
		j++;
	}
	return (str2);
}

t_perso 	**ft_decrypt(char *str)
{
	int				i;
	int				j;
	t_perso			**textttt_perso;

	i = 0;
	j = 0;
    textttt_perso = malloc(sizeof(*textttt_perso) * numberofstructs(str) + 1);
	while (j <= ft_strlen(str) && str[j])
	{
		if (str[j] == ';')
		{
				i++;
				j++;
		}
    		textttt_perso[i] = malloc(sizeof(*textttt_perso[i]));
    		//textttt_perso[i] = malloc(sizeof(**textttt_perso));
   			textttt_perso[i]->age = ft_atoi(get_data(str, j));
    		j = j + get_data_length(str, j) + 1;
			textttt_perso[i]->name = get_data(str, j);
			j = j + get_data_length(str, j);
	}
	textttt_perso[i+1] = 0;
	return textttt_perso;
}

int		main(void)
{
	int i;
	t_perso **tab;
	
	i = 0;
	char 		str[29] = "123|Nomzer;456|REBE;789|DEREr";
	tab = ft_decrypt(str);
	while(i <= numberofstructs(str))
	{
		ft_putnbr_and_nl(tab[i]->age);
		ft_putstr(tab[i]->name);
		ft_putchar('\n');
		i++;
	}
}