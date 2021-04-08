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

t_list  *ft_list_last(t_list *begin_list)
{
    t_list  *list;

    list = begin_list;
    if (list)
    {
        while (list->next)
            list = list->next;
        return (list);
    }
    return (NULL);
}

void ft_print_list(t_list *list)
{
    while (list)
    {
        printf("%p\n", list);
        list = list->next;
    }
}

int        main(void)
{
    int a;
    int b;
    int c;

    a = 7;
    b = 8;
    c = 9;

    t_list *begin_list;
    begin_list = ft_create_elem(&a);
    begin_list->next = ft_create_elem(&b);
    begin_list->next->next = ft_create_elem(&c);

    printf("liste\n");
    ft_print_list(begin_list);
    printf("last\n");
    printf("%p", (void *)ft_list_last(begin_list));
    return (0);
}