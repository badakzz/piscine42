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

void  ft_list_foreach_if(t_list *begin_list, void (*f)(void *), void *data_ref, int (*cmp)())
{
    t_list  *list_ptr;

    list_ptr = begin_list;
    while (list_ptr)
    {
        if ((*cmp)(list_ptr->data, data_ref) > 0)
            (*f)(list_ptr->data);
        list_ptr = list_ptr->next;
    }
}

void ft_print_list(t_list *list)
{
    while (list)
    {
        printf("%p\n", list);
        list = list->next;
    }
}   

int ft_strcmp(char *s1, const char *s2)
{
    int x;

    x = 0;
    while (s1[x] == s2[x] && s1[x] != '\0' && s2[x] != '\0')
        x++;
    return (s1[x] - s2[x]);
}

void     ft_add2(void *data)
{
    data = data + 2;
    return;
}

int        main(void)
{
    int a;
    int b;
    int c;
    char str[] = "zebi";

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
    ft_list_foreach_if(begin_list, &ft_add2, str, &ft_strcmp);
    ft_print_list(begin_list);
    return (0);
}