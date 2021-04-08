#include "ft_list.h"
#include <stdlib.h>
#include <stdio.h>

t_list	*ft_create_elem(void *data)
{
	t_list	*list;

	list = NULL;
	list = malloc(sizeof(t_list));
	if (list)
	{
		list->data = data;
		list->next = NULL;
	}
	return (list);
}

void ft_print_list(t_list *list)
{
    while (list)
    {
        printf("%p\n", list);
        list = list->next;
    }
}

t_list	*ft_list_push_params(int ac, char **av)
{
    int     i;
    t_list  *list;
	t_list	*new_node;

    i = 1;
    while (i < ac)
    {
        new_node = ft_create_elem(av[i]);
        new_node->next = list;
        list = new_node;
        i++;
    }
    return (list);
}

int     main(int ac, char **av)
{
    t_list *list;

    list = ft_list_push_params(ac, av);

    ft_print_list(list);
}