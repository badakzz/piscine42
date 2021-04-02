#include "ft_door.h"
#include <unistd.h>
#include <stdlib.h>


void 	ft_putstr(char *str)
{
	int i;

	i = 0;
	while (str[i])
	{
		write(1, &str[i], 1);
		i++;
	}
}

void ft_close_door(t_door *door)
{

	ft_putstr("Door closing...");
	door->state = CLOSE;
	return;
}

t_bool is_door_open(t_door *door)
{
	ft_putstr("Is door open ?");
	return (door->state == OPEN);
}

t_bool is_door_close(t_door *door)
{
	ft_putstr("Is door close ?");
	return (door->state == CLOSE);
}

int		main(void)
{
	t_door *door;
	door = malloc(sizeof(t_door));
	door->state = OPEN;
	is_door_open(door);
	is_door_close(door);
	ft_close_door(door);
	is_door_open(door);
	is_door_close(door);
}