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

void	ft_list_push_front(t_list **begin_list, void *data)
{
    t_list  *new_node;

    new_node = ft_create_elem(data);
	if (new_node)
	{
        new_node->next = *begin_list;
        *begin_list = new_node;
	}
	else
		new_node = ft_create_elem(data);
	return;
}

void ft_print_list_data(t_list *list)
{
    while (list)
    {
        printf("%p\n", list->data);
        list = list->next;
    }
}

int        main(void)
{
    int a;
    int b;
    int c;
    int d;

    a = 7;
    b = 8;
    c = 9;
    d = 1;
    
    t_list *begin_list;
    begin_list = ft_create_elem(&a);
    begin_list->next = ft_create_elem(&b);
    begin_list->next->next = ft_create_elem(&c);

    printf("liste\n");
    ft_print_list(begin_list);
    printf("ajouter 1 element au debut\n");
    ft_list_push_front(&begin_list, &d);
    printf("liste upated\n");
    ft_print_list(begin_list);
    return (0);
}