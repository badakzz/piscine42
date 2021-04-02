char	*ft_strstr(char *str, char *to_find)
{
	int i;
	int j;
	int bool;
	int size;

	i = 0;
	j = 0;
	bool = 0;
	size = 0;

	while (to_find[size])
		size++;
	if (size == 0)
		return (str);
	while(str[i])
	{
		if(str[i] == to_find[0])
		{
			bool = 1;
			j = i;
			i = 0;
			break;
		}
		i++;
	}
	i = 0;
	while(str[j])    // pas str[i] car on le remplace, il n existe plus. tant que cest une moto, on fait des tours, mais ma moto devient une voiture. on a transforme les motos en voiture donc on ne peut plus regarder les motos, il faut regarder les voitures
	{
		str[i] = str[j];
		j++;
		i++;
	}
	str[i] = '\0';
	if(bool == 0)
		return (0);
	return (str);
}