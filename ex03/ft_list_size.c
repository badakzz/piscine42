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

int ft_list_size(t_list *begin_list)
{
    t_list  *list;
    int     i;

    i = 0;
    list = begin_list;
    while (list)
    {
        list = list->next;
        i++;
    }
    return (i);
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

    printf("%d", ft_list_size(begin_list));
    return (0);
}