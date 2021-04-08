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

void	ft_list_clear_alt(t_list *list)
{
	t_list		*next;

	if (list)
		return;
	next = list->next;
	free(list);
	ft_list_clear_alt(next);

}

void	ft_list_clear(t_list **begin_list)
{
	ft_list_clear_alt(*begin_list);
	*begin_list = NULL;
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
    ft_list_clear(&begin_list);
    printf("liste upated\n");
    ft_print_list(begin_list);
    return (0);
}
